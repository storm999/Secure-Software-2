#ifndef Subject_h
#define Subject_h
#pragma once

class Authenticator;
#include <iostream>
#include "ResourceFactory.h"
#include "Device.h"

using namespace std;

class Subject
{
private:
	string userName;
	string password;
	string proofOfId;

public:
	Subject(string newId, string pass);
	Subject();
	~Subject();

	string getId();

	string getProofOfId();

	void setProofOfId(string newId);

	string getPassword();

	void accessResource(Authenticator* authenticator, Device* device);
	short logINorExit();
};

#endif 