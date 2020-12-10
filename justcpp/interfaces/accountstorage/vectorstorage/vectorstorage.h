#ifndef VECTOR_STORAGE_INCLUDED
#define VECTOR_STORAGE_INCLUDED

#include "..\\account\\account.h"
#include "..\\Iaccountstorage\\Iaccountstorage.h"
#include <vector>
#include <string>

class VectorAccountStorage : public IAccountStorage
{
public:
	~VectorAccountStorage();
	void AddAccount(std::string id) override;
	Account *GetAccount(std::string id) override;
private:
	std::vector<Account *> accounts;
};

#endif
