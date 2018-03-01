#include "DeviceInterface.h"
#include "Authenticator.h"

DeviceInterface::DeviceInterface()
{
}


DeviceInterface::~DeviceInterface()
{
}

unsigned DeviceInterface::printMenu()
{
	cout << "What would you like to do?" << endl;
	cout << "0 log out" << endl;
	cout << "1 display values of sensors" << endl;
	cout << "2 display previous records" << endl;
	cout << "3 list users" << endl;
	cout << "4 add user" << endl;
	cout << "5 delete user" << endl;
	return 5;
}
 
void DeviceInterface::executeFunctionality(unsigned requestedResource, Authenticator* authenticator, Device* device)
{	
	switch (requestedResource)
	{
		case 0: cout << "Logging out." << endl;
			break;
		case 1: device->displayValues();
			break; 
		case 2: device->printLogToScreen();
			break;
		case 3: authenticator->getAuthenticationInfo()->listUsers();
			break;
		case 4: authenticator->getAuthenticationInfo()->addUser();
			break;
		case 5: authenticator->getAuthenticationInfo()->deleteUser();
			break;
		default: cout << "Invalid input." << endl;
			break;
	}
}