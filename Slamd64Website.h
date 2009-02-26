#include <FastCgiQt/ServiceMapper.h>

#include <QObject>

class Slamd64Website: public FastCgiQt::ServiceMapper
{
	Q_OBJECT;
	SERVICE_MAPPER(Slamd64Website);
	protected:
		void loadServices();
};
