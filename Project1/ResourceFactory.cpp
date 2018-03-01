#include "ResourceFactory.h"

ResourceFactory::ResourceFactory()
{
}


ResourceFactory::~ResourceFactory()
{
}

void ResourceFactory::accessResource(Authenticator* authenticator, Device* device)
{
	Resource res;
	res.newResource(authenticator, device);
}