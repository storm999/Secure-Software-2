#include "Authenticator.h"

Authenticator::Authenticator()
{
}

Authenticator::~Authenticator()
{
}

ProofOfId* Authenticator::authenticateUser(Subject* subject)
{
	ProofOfId* proofOfId = nullptr;
	string id = subject->getId();
	string pass = subject->getPassword();
	string token = "";
	aInfo = new AuthenticationInfo();
	
	userType = aInfo->validateUser(id, pass);
	
	if (userType != -1)
	{
		token = encryptDecrypt(id + pass);
		proofOfId = new ProofOfId(token);
		subject->setProofOfId(token);
		cout << "You are authenticated with " + proofOfId->getProofId() + " proof ID." << endl;
	}
	else
	{
		cout << "Invalid id or pass" << endl;
	}
	return proofOfId;
}

string Authenticator::encryptDecrypt(string toBeProcessed)
{
	string ret = toBeProcessed;
	char key = 'A';
	for (unsigned i = 0; i < toBeProcessed.size(); i++)
	{
		ret[i] = toBeProcessed[i] ^ key;
	}
	return ret;
}

int Authenticator::getUserType()
{
	return userType;
}

AuthenticationInfo* Authenticator::getAuthenticationInfo()
{
	return aInfo;
}