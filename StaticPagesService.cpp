#include "StaticPagesService.h"

#include <QDebug>

StaticPagesService::StaticPagesService(const FastCgiQt::Request& request, QObject* parent)
	:
		XsltService(request, parent)
{
}

void StaticPagesService::showStaticPage(const QString& pageName)
{
	cacheThisRequest();
	// page Name validation done by regex in urlMap
	addXsltFile("xslt/header.xsl");
	addXsltFile("xslt/static.xsl");
	addXsltFile("xslt/footer.xsl");

	QList<QString> validPages;
	validPages
		<< "about"
		<< "support"
		<< "thanks"
		<< "contact"
	;
	if(validPages.contains(pageName))
	{
		QXmlStreamReader reader(readFile(QString("static/%1.xhtml").arg(pageName)));
		while(!reader.atEnd())
		{
			reader.readNext();
			if(reader.hasError())
			{
				qDebug() << "XML error in" << pageName << reader.errorString();
				break;
			}
			xmlOut.writeCurrentToken(reader);
		}
	}
	else
	{
		xmlOut.writeStartDocument();
		xmlOut.writeTextElement("error", "not a valid page");
	}
}

FastCgiQt::Service::UrlMap StaticPagesService::urlMap() const
{
	FastCgiQt::Service::UrlMap map;
	map.append("(.*)", SLOT(showStaticPage(QString)));
	return map;
}
