#ifndef MAP_STORAGE_INCLUDED
#define MAP_STORAGE_INCLUDED



#include "..\\account\\account.h"
#include "..\\Iaccountstorage\\Iaccountstorage.h"
#include <map>
#include <string>


// alias - makes for prettier code
using mapStorage = std::map<std::string, Account *>;


class MapAccountStorage : public IAccountStorage
{
  public:
  	~MapAccountStorage();
  	void AddAccount(std::string id) override;
  	Account *GetAccount(std::string id) override;
  private:
  	mapStorage accounts;
};

#endif
