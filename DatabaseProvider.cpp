#include "DatabaseProvider.h"

#include <FastCgiQt/Database.h>

#include <QCoreApplication>
#include <QMutex>
#include <QMutexLocker>
#include <QSettings>
#include <QSqlError>
#include <QStringList>

QSqlDatabase DatabaseProvider::database()
{
	static QMutex mutex;
	QMutexLocker lock(&mutex);

	// Do we already have one?
	if(FastCgiQt::Database::haveConnection())
	{
		return FastCgiQt::Database::database(true);
	}

	// nope, make one
	const QString appName = QCoreApplication::applicationName();
	const QString configFilePath = QCoreApplication::applicationDirPath() + "/." + QCoreApplication::applicationFilePath().split("/").last();
	QSettings settings(configFilePath, QSettings::IniFormat);

	QSqlDatabase db = FastCgiQt::Database::addDatabase("QMYSQL");
	db.setHostName(settings.value("database/server", "localhost").toString());
	db.setDatabaseName(settings.value("database/name", appName).toString());
	db.setUserName(settings.value("database/user", appName).toString());
	db.setPassword(settings.value("database/password", appName).toString());

	if(!db.open())
	{
		qFatal("Couldn't open a database connection: %s", qPrintable(db.lastError().text()));
	}

	return db;
}
