#ifndef Resource_h
#define Resource_h
#pragma once
class Authenticator;
#include "Device.h"
#include <iostream>
#include <string>
#include "DeviceInterface.h"
#include "Permission.h"

using namespace std;

class Resource
{

public:
	Resource();
	~Resource();

	void newResource(Authenticator* authenticator, Device* device);
};

#endif 