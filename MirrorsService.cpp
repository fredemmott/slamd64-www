#include "MirrorsService.h"

#include "DatabaseProvider.h"

#include <QDate>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

MirrorsService::MirrorsService(const FastCgiQt::Request& request, QObject* parent)
	:
		XsltService(request, parent)
{
	setUsingFileCache(true);
	setPrettyPrintingEnabled(true);
	xmlOut.writeDefaultNamespace("http://slamd64.com/1.0");
}

void MirrorsService::listMirrors()
{
	cacheThisRequest();
	addXsltFile("xslt/header.xsl");
	addXsltFile("xslt/mirrors.xsl");
	addXsltFile("xslt/footer.xsl");

	xmlOut.writeStartDocument();

	xmlOut.writeStartElement("mirrors");
	xmlOut.writeStartElement("head");
		xmlOut.writeStartElement("meta");
			xmlOut.writeAttribute("name", "pageName");
			xmlOut.writeAttribute("content", "download");
		xmlOut.writeEndElement();
		xmlOut.writeTextElement("title", tr("Download"));
	xmlOut.writeEndElement();
	QSqlQuery query(DatabaseProvider::database());
	QMap<QString, int> locations;
	query.exec("SELECT name, id FROM slamd64_mirror_locations");
	for(query.first(); query.isValid(); query.next())
	{
		locations.insert(query.value(0).toString(), query.value(1).toInt());
	}

	for(
		QMap<QString, int>::ConstIterator it = locations.constBegin();
		it != locations.constEnd();
		++it
	)
	{
		xmlOut.writeStartElement("location");
			xmlOut.writeTextElement("name", it.key());
			xmlOut.writeStartElement("servers");
				query.prepare("SELECT name, ftp, http, rsync FROM slamd64_mirrors WHERE location = :location ORDER BY name ASC");
				query.bindValue(":location", it.value());
				query.exec();
				for(query.first(); query.isValid(); query.next())
				{
					const QString name = query.value(0).toString();
					const QString ftp = query.value(1).toString();
					const QString http = query.value(2).toString();
					const QString rsync = query.value(3).toString();

					xmlOut.writeStartElement("server");
						xmlOut.writeTextElement("name", name);
						if(!ftp.isNull()) xmlOut.writeTextElement("ftp", ftp);
						if(!http.isNull()) xmlOut.writeTextElement("http", http);
						if(!rsync.isNull()) xmlOut.writeTextElement("rsync", rsync);
					xmlOut.writeEndElement();
				}
			xmlOut.writeEndElement();
		xmlOut.writeEndElement();
	}
}

FastCgiQt::Service::UrlMap MirrorsService::urlMap() const
{
	FastCgiQt::Service::UrlMap map;
	map.append(".*", SLOT(listMirrors()));
	return map;
}
