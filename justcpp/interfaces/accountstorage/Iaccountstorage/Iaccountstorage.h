#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED
#include "..\\account\\account.h"
#include <string>

class IAccountStorage
{
public:
	virtual void AddAccount(std::string id) = 0;
	virtual Account *GetAccount(std::string id) = 0;
};

#endif
