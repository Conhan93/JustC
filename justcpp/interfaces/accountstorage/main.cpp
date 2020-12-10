





#include "account\\account.h"
#include "Iaccountstorage\\Iaccountstorage.h"
#include "distributedvector\MultiDistributedVectorAccountStorage.h"
#include "mapstorage\MapAccountStorage.h"
#include "vectorstorage\vectorstorage.h"

#include <chrono>
#include <iostream>



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
  using clock = std::chrono::high_resolution_clock;
  clock::time_point start;
  clock::time_point end;

  VectorAccountStorage *storage = new VectorAccountStorage();
  //MapAccountStorage *storage = new MapAccountStorage();
  //MultiDistributedVectorAccountStorage *storage = new MultiDistributedVectorAccountStorage();
  Bank bank = Bank(storage);

  for(int i = 0; i < 100000; i++)
    bank.AddAccount(std::to_string(i));

  std::string accountNr;
  while (1)
  {
    std::cout << "Ange kontonummer:>" ;
    std::getline(std::cin,accountNr);

    start = clock::now();

    Account *acc = bank.GetAccount(accountNr);

    end = clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << (acc == nullptr ? "Account not found " : "Account found ")
    << "time: " << duration << " ms " << std::endl;
  }
}
