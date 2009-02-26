#include <FastCgiQt/XsltService.h>

class NewsService : public FastCgiQt::XsltService
{
	Q_OBJECT;
	SERVICE(NewsService);
	public:
		NewsService(const FastCgiQt::Request&, QObject* parent = NULL);
	public slots:
		void listNews();
	protected:
		FastCgiQt::Service::UrlMap urlMap() const;
};
