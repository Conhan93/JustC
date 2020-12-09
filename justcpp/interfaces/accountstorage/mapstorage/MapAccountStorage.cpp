#include "MapAccountStorage.h"
#include <algorithm>


MapAccountStorage::~MapAccountStorage()
{
  using mapIter = mapStorage::const_iterator;

  for (mapIter it = accounts.begin(); it != accounts.end(); it++)
	{
		delete  it->second;
	}
}
void MapAccountStorage::AddAccount(std::string id)
{
  Account *account = new Account(id);
	accounts[id] = account;
}
Account* MapAccountStorage::GetAccount(std::string id)
{
  return accounts[id];
}
