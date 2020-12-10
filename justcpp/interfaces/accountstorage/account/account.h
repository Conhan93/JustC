#ifndef ACCOUNT_INCLUDED
#define ACCOUNT_INCLUDED

#include <string>

class Account
{
public:
	Account(std::string id, float balance = 0);
	std::string GetId();
private:
	std::string id;
	float balance;
};

#endif
