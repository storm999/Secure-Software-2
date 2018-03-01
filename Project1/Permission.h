#ifndef Permission_h
#define Permission_h
#pragma once

#include <vector>
#include <map>

using namespace std;

enum userTypes { ADMIN, USER, NUMBER_OF_USER_TYPES };

class Permission
{
private:
	map <unsigned, vector<unsigned> > roleResourceAccessMap;

public:
	Permission();
	~Permission();
	bool checkPermission(unsigned requestedResource, unsigned userType);
};

#endif 