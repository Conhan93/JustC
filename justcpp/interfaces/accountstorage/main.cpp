





#include "account\\account.h"
#include "Iaccountstorage\\Iaccountstorage.h"
#include "distributedvector\MultiDistributedVectorAccountStorage.h"
#include "mapstorage\MapAccountStorage.h"
#include "vectorstorage\vectorstorage.h"



class Bank
{
  public:
  	Bank(IAccountStorage *storage)
    {
	     accountStorage = storage;
    }
  	bool AddAccount(std::string id)
    {
        accountStorage->AddAccount(id);
 	      return true;
    }
  	Account *GetAccount(std::string id)
    {
      return accountStorage->GetAccount(id);
    }
  private:
  	IAccountStorage* accountStorage;
};


int main()
{
  
}
