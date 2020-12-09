#include "MultiDistributedVectorAccountStorage.h"


MultiDistributedVectorAccountStorage::~MultiDistributedVectorAccountStorage()
{
    for(accountVector accounts : accountVectors)
      for(Account* account : accounts)
        delete account;
}
int MultiDistributedVectorAccountStorage::IdToIndex(std::string id)
{
  return stoi(id.substr(0,2));
}
void MultiDistributedVectorAccountStorage::AddAccount(std::string id)
{
  int index = IdToIndex(id);

  accountVectors[index].push_back(new Account(id));
}
Account* MultiDistributedVectorAccountStorage::GetAccount(std::string id)
{
  int index = IdToIndex(id);

  for(Account* account : accountVectors[index])
    if(account->GetId() == id)
      return account;

  return nullptr;
}
