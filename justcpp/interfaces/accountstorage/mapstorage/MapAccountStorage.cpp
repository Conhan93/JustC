#include "MapAccountStorage.h"
#include <algorithm>


MapAccountStorage::~MapAccountStorage()
{
  // alias
  using mapIter = mapStorage::const_iterator;

  for (mapIter it = accounts.begin(); it != accounts.end(); it++)
		delete  it->second;

    /*
        Deconstructor called at end of object lifetime.

        this one loops through all accounts and frees the
        allocated memory for them(since they're created using new)
    */
}
void MapAccountStorage::AddAccount(std::string id)
{
  Account *account = new Account(id);
	accounts[id] = account;
  /*
      Maps work just like dictionaries in Python,
      except that you have to declare types for keys
      and values when declaring a map.

      here string ID is used as a key and account
      is saved as value
  */
}
Account* MapAccountStorage::GetAccount(std::string id)
{
  // fetches, value at key - the account with the ID key
  return accounts[id];
}
