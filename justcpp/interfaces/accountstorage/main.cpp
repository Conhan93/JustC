





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
        // uses functions declared in interface class! overriden
        // by implementation, uses implementation method
        accountStorage->AddAccount(id);
 	      return true;
    }
  	Account *GetAccount(std::string id)
    {
      // uses functions declared in interface class! overriden
      // by implementation, uses implementation method
      return accountStorage->GetAccount(id);
    }
  private:
  	IAccountStorage* accountStorage;

    /*
      Interface class pointers are able to point to implementations
      of interface.

      IAccountStorage pointer is able to point to any class inheriting
      from it, vectorStorage, MapAccountStorage and multivectorstorage.

      so bank can support any implementation of IAccountStorage without
      having to know anything about that implementation!

      Also since it is a pointer, it can be reassigned. Bank can change
      storage method while the program is still running just by reassigning
      the pointer to a different implementation!(not possible with references)
    */
};


int main()
{
  // alias makes for prettier code
  using clock = std::chrono::high_resolution_clock;
  clock::time_point start;
  clock::time_point end;


  // implementations of IAccountStorage!! polymorphisms
  VectorAccountStorage *storage = new VectorAccountStorage();
  //MapAccountStorage *storage = new MapAccountStorage();
  //MultiDistributedVectorAccountStorage *storage = new MultiDistributedVectorAccountStorage();



  Bank bank = Bank(storage);

  for(int i = 0; i < 1000000; i++)
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
