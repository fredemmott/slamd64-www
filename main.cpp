#include "Slamd64Website.h"

#include <FastCgiQt/Manager.h>
#include <QCoreApplication>

int main(int argc, char** argv)
{
	QCoreApplication application(argc, argv);
	application.setApplicationName("Slamd64Website");

	FastCgiQt::Manager manager(&Slamd64Website::create);
	return application.exec();
}
