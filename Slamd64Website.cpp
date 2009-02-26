#include "Slamd64Website.h"

#include "StaticPagesService.h"

void Slamd64Website::loadServices()
{
	addService("", StaticPagesService::create);
}
