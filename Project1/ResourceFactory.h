#ifndef ResourceFactory_h
#define ResourceFactory_h
#pragma once

class Authenticator;

#include "Device.h"
#include "Resource.h"


class ResourceFactory
{
public:
	ResourceFactory();
	~ResourceFactory();

	void accessResource(Authenticator* authenticator, Device* device);
};

#endif 