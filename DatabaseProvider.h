#ifndef _DATABASE_PROVIDER_H
#define _DATABASE_PROVIDER_H

#include <QSqlDatabase>

class DatabaseProvider
{
	public:
		static QSqlDatabase database();
};

#endif
