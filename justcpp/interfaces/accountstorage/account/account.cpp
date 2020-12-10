#include "account.h"




Account::Account(std::string id, float balance)
{
  this->id = id;
  this->balance = balance;
}

std::string Account::GetId()
{
  return this->id;
}
