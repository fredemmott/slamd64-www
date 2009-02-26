#include "Slamd64Website.h"

#include "NewsService.h"
#include "StaticPagesService.h"

void Slamd64Website::loadServices()
{
	addService("news", NewsService::create);
	addService("", StaticPagesService::create);
}
