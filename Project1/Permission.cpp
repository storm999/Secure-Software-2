#include "Permission.h"

Permission::Permission()
{
	roleResourceAccessMap[ADMIN] = { true, true, true, true, true, true };
	roleResourceAccessMap[USER] = { true, true, true, true, false, false };
}

Permission::~Permission()
{
}

bool Permission::checkPermission(unsigned requestedResource, unsigned userType)
{
	if (roleResourceAccessMap[userType].at(requestedResource))
	{
		return true;
	}
	else
	{
		return false;
	}
}