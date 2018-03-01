#include "Subject.h"

Subject::Subject(string newName, string newPass)
{
	userName = newName;
	password = newPass;
}

Subject::Subject()
{
	cout << "Enter userID: ";
	cin >> userName;
	cout << "Enter password: ";
	cin >> password;
	proofOfId = "";
}

Subject::~Subject()
{
}

void Subject::accessResource(Authenticator* authenticator, Device* device)
{
	ResourceFactory *resourceFactory = new ResourceFactory();
	resourceFactory->accessResource(authenticator, device);
	delete resourceFactory;
}

string Subject::getId()
{
	return userName;
}

string Subject::getProofOfId()
{
	return proofOfId;
}

void Subject::setProofOfId(string newId)
{
	proofOfId = newId;
}

string Subject::getPassword()
{
	return password;
}

short Subject::logINorExit()
{
	short  ret = -1;

	cout << "Press 0 for secure exit\nPress 1 to log in" << endl;

	short fail = false;
	do
	{
		fail = (cin >> ret).fail();
		if (fail)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Try again: " << endl;
		}
	} while (fail || ret < 0 || ret > 1); 
	
	return ret;
}