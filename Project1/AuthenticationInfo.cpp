#include "AuthenticationInfo.h"

AuthenticationInfo::AuthenticationInfo()
{
	userMap.push_back(tuple< string, string, unsigned>( "admin", "admin", ADMIN));
	userMap.push_back(tuple< string, string, unsigned>( "user", "user", USER));
}

AuthenticationInfo::~AuthenticationInfo()
{
}

int AuthenticationInfo::validateUser(string userName, string password)
{
	for (unsigned i = 0; i < userMap.size(); i++)
	{
		if (get<0>(userMap[i]) == userName && get<1>(userMap[i]) == password)
		{
			return get<2>(userMap[i]);
		}
	}
	return -1;
}

void AuthenticationInfo::listUsers()
{
	for (unsigned i = 0; i < userMap.size(); i++)
	{
		cout << i << " ->User name: " << get<0>(userMap[i]) << ", User Type: " << get<2>(userMap[i]) << endl;
	}
}

void AuthenticationInfo::addUser()
{
	string userName = "";
	string password = "";
	unsigned type;

	cout << "Enter username: ";
	cin >> userName;
	cout << "Enter password: ";
	cin >> password;

	cout << "Enter user type. " << endl;
	cout << "0 -> Admin" << endl;
	cout << "1 -> User" << endl;

	bool fail = false;
	do
	{
		fail = (cin >> type).fail();
		if (fail)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Try again: " << endl;
		}
		if (type < 0 || NUMBER_OF_USER_TYPES <= type)
		{
			cout << "Invalid input. Try again: " << endl;
		}
	} while (fail || type < 0 || NUMBER_OF_USER_TYPES <= type);

	userMap.push_back(tuple< string, string, unsigned>(userName, password, type));
	cout << "User added." << endl;
}

void AuthenticationInfo::deleteUser()
{
	listUsers();
	cout << "Which user do you want to delete?" << endl;
	unsigned toBeDeleted = -1;

	bool fail = false;
	do
	{
		fail = (cin >> toBeDeleted).fail();
		if (fail)
		{
			cin.clear();
			cin.ignore();
			cout << "Invalid input. Try again: " << endl;
		}
		if (toBeDeleted < 0 || toBeDeleted > userMap.size())
		{
			cout << "Invalid input. Try again: " << endl;
		}
	} while (fail || toBeDeleted < 0 || toBeDeleted > userMap.size() );

	userMap.erase(userMap.begin() + toBeDeleted);
	cout << "User has been deleted." << endl;
}