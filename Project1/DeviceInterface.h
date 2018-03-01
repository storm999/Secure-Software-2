#ifndef DeviceInterface_h
#define DeviceInterface_h
#pragma once

class Authenticator;
class Device;
#include "AuthenticationInfo.h"
#include <iostream>

using namespace std;

class DeviceInterface
{
public:
	DeviceInterface();
	~DeviceInterface();

	unsigned printMenu();
	void executeFunctionality(unsigned requestedResource, Authenticator* authenticator, Device* device);
};

#endif 