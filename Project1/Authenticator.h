#ifndef Authenticator_h
#define Authenticator_h
#pragma once

#include <iostream>
#include "AuthenticationInfo.h"
#include "ProofOfId.h"
#include "Subject.h"

using namespace std;

class Authenticator
{
private:
	int userType;
	AuthenticationInfo* aInfo = nullptr;
public:
	Authenticator();
	~Authenticator();

	ProofOfId* authenticateUser(Subject* subject);
	string encryptDecrypt(string toBeProcessed);
	int getUserType();
	AuthenticationInfo* getAuthenticationInfo();
};

#endif 