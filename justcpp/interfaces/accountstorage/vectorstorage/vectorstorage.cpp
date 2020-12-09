#include "vectorstorage.h"



VectorAccountStorage::~VectorAccountStorage()
{
  for(Account* account : accounts)
    delete account;
}
void VectorAccountStorage::AddAccount(std::string id)
{
  Account *account = new Account(id);
  accounts.push_back(account);
}
Account* VectorAccountStorage::GetAccount(std::string id)
{
  for(Account* account : accounts)
    if(account->GetId() == id) return account;

  return nullptr;
}
