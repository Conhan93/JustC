#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED
#include "..\\account\\account.h"
#include <string>


/*
		Interface class used to define interactions with derived classes
		in this case the different version of accountstorage(vec, multivec & map)

*/
class IAccountStorage
{
	public:
		virtual void AddAccount(std::string id) = 0;
		virtual Account *GetAccount(std::string id) = 0;
		/*
			Virtual function are able to be overloaded/overwritten by
			derived classes using "override" and provide their own
			definition of the function

			virtual + the " = 0;" creates a "pure virtual" function.
			you're not allowed to create instantiations of classes
			containing pure virtual functions.

			meaning that any derived classes of the interface has
			to override and implement a version of the functions.

		*/
};

#endif
