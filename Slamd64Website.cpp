#include "Slamd64Website.h"

#include "MirrorsService.h"
#include "NewsService.h"
#include "StaticPagesService.h"

void Slamd64Website::loadServices()
{
	addService("get", MirrorsService::create);
	addService("", StaticPagesService::create);
	addService("news", NewsService::create);
}
