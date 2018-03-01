#include <iostream>
#include "Authenticator.h" 
#include "Device.h"

using namespace std;

int main()
{
	Authenticator* authenticator = new Authenticator();
	Device* device = new Device();
	short secureLogOff = 1;
	
	while (secureLogOff == 1)	// Provides changing user without closing app
	{
		Subject* subject = nullptr;
		ProofOfId* proofOfId = nullptr;
				
		while (proofOfId == nullptr && secureLogOff == 1)
		{
			secureLogOff = subject->logINorExit();
			
			if (secureLogOff == 1)
			{
				subject = new Subject();
				proofOfId = authenticator->authenticateUser(subject);
			}

			if (proofOfId == nullptr)
			{
				delete subject;
			}				
		}
		if (secureLogOff == 1)
		{
			subject->accessResource(authenticator, device);
		}
		
		delete subject;
		delete proofOfId;
	}

	for (unsigned i = 0; i < device->getSensors().size(); i++)
	{
		delete(device->getSensors()[i]);
	}
	delete device;	

	delete (authenticator->getAuthenticationInfo());
	delete authenticator;
	
	return 0;
}
