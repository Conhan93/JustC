#ifndef DISTRIBUTED_VECTOR_INCLUDED
#define DISTRIBUTED_VECTOR_INCLUDED


#include "..\\account\\account.h"
#include "..\\Iaccountstorage\\Iaccountstorage.h"
#include <vector>
#include <string>

// alias
using accountVector = std::vector<Account *>;

class MultiDistributedVectorAccountStorage : public IAccountStorage
{
  public:
  	MultiDistributedVectorAccountStorage();
  	~MultiDistributedVectorAccountStorage();
  	void AddAccount(std::string id) override;
  	Account *GetAccount(std::string id) override;
  private:
    // internal utility func
    int IdToIndex(std::string id);
    
  	std::vector<accountVector> accountVectors;
};

#endif
