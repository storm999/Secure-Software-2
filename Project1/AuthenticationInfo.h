#ifndef AuthenticationInfo_h
#define AuthenticationInfo_h
#pragma once

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include "Permission.h"

using namespace std;

class AuthenticationInfo
{
				//username, password, accessType
	vector < tuple <string, string, unsigned> > userMap;
public:
	AuthenticationInfo();
	~AuthenticationInfo();

	int validateUser(string userName, string password);

	void listUsers();
	void addUser();
	void deleteUser();

};

#endif 