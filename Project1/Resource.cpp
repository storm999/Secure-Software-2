#include "Resource.h"
#include "Authenticator.h"

Resource::Resource()
{	
}

Resource::~Resource()
{
}

void Resource::newResource(Authenticator* authenticator, Device* device)
{
	bool loggedIn = true;
	unsigned requestedResource = -1;
	
	while (loggedIn && requestedResource != 0)
	{
		DeviceInterface* deviceInterface = new DeviceInterface();
		Permission *permission = new Permission();
		device->randomizeSensorValueAll();
		device->log();

		unsigned numberOfOptions = deviceInterface->printMenu();
		
		bool fail = false;
		do 
		{
			fail = (cin >> requestedResource).fail();
			if (fail)
			{
				cin.clear();
				cin.ignore();
				cout << "Invalid input. Try again: " << endl;
			}		
		} while (fail || requestedResource < 0 || requestedResource> numberOfOptions);


		if (permission->checkPermission(requestedResource, authenticator->getUserType()))
		{
			cout << "Access granted." << endl;
			deviceInterface->executeFunctionality(requestedResource, authenticator, device);
		}
		else
		{
			cout << "You have no access right. Contact to admin." << endl;
		}
		
		delete deviceInterface;
		delete permission;
	}
}

