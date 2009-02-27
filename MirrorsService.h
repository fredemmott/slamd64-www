#include <FastCgiQt/XsltService.h>

class MirrorsService : public FastCgiQt::XsltService
{
	Q_OBJECT;
	SERVICE(MirrorsService);
	public:
		MirrorsService(const FastCgiQt::Request&, QObject* parent = NULL);
	public slots:
		void listMirrors();
	protected:
		FastCgiQt::Service::UrlMap urlMap() const;
};
