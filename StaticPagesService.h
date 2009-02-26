#include <FastCgiQt/XsltService.h>

class StaticPagesService : public FastCgiQt::XsltService
{
	Q_OBJECT;
	SERVICE(StaticPagesService);
	public:
		StaticPagesService(const FastCgiQt::Request&, QObject* parent = NULL);
	public slots:
		void showStaticPage(const QString& pageName);
	protected:
		FastCgiQt::Service::UrlMap urlMap() const;
};
