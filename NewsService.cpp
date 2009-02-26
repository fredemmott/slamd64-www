#include "NewsService.h"

#include "DatabaseProvider.h"

#include <QDate>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

NewsService::NewsService(const FastCgiQt::Request& request, QObject* parent)
	:
		XsltService(request, parent)
{
	setUsingFileCache(true);
	setPrettyPrintingEnabled(true);
	xmlOut.writeDefaultNamespace("http://slamd64.com/1.0");
}

void NewsService::listNews()
{
	cacheThisRequest();
	addXsltFile("xslt/header.xsl");
	addXsltFile("xslt/news.xsl");
	addXsltFile("xslt/footer.xsl");

	xmlOut.writeStartDocument();

	xmlOut.writeStartElement("news");
	QSqlQuery query(DatabaseProvider::database());
	query.exec("SELECT title, content, date, poster, editor, editDate FROM slamd64_news ORDER BY id DESC");
	for(query.first(); query.isValid(); query.next())
	{
		QString title = query.value(0).toString();
		QString xmlContent = "<body>" + query.value(1).toString() + "</body>";
		QDate posted = QDate::fromString(query.value(2).toString(), "yyyyMMdd");
		QString poster = query.value(3).toString();
		QString editor = query.value(4).toString();
		QDate edited = QDate::fromString(query.value(5).toString(), "yyyyMMdd");

		xmlOut.writeStartElement("newsItem");
			xmlOut.writeTextElement("title", title);
			xmlOut.writeTextElement("poster", poster);
			xmlOut.writeTextElement("posted", posted.toString(Qt::ISODate));
			if(!editor.isNull())
			{
				xmlOut.writeTextElement("editor", editor);
				xmlOut.writeTextElement("edited", edited.toString(Qt::ISODate));
			}
			QXmlStreamReader reader(xmlContent);
			xmlOut.writeStartElement("body");
				QList<QXmlStreamReader::TokenType> allowedTokenTypes;
				allowedTokenTypes
					<< QXmlStreamReader::StartElement
					<< QXmlStreamReader::EndElement
					<< QXmlStreamReader::Characters
					<< QXmlStreamReader::EntityReference
				;
				while((!reader.atEnd()) && reader.readNext())
				{
					if(reader.hasError())
					{
						qFatal("Parse error: %s", qPrintable(reader.errorString()));
					}
					if(allowedTokenTypes.contains(reader.tokenType()))
					{
						if(!((reader.isStartElement() || reader.isEndElement())&& reader.name() == "body"))
						{
							xmlOut.writeCurrentToken(reader);
						}
					}
				}
			xmlOut.writeEndElement();
		xmlOut.writeEndElement();
	}
}

FastCgiQt::Service::UrlMap NewsService::urlMap() const
{
	FastCgiQt::Service::UrlMap map;
	map.append(".*", SLOT(listNews()));
	return map;
}
