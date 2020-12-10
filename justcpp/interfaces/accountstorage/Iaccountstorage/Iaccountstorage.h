#ifndef INTERFACE_INCLUDED
#define INTERFACE_INCLUDED
#include "..\\account\\account.h"
#include <string>

/*
    Interface classes act as... interfaces, a template for derived classes
		and how functions/interfaces for how to interact with implementations
		of the class.

		The class consists of public pure virtual methods which defines how
		the user of the class implementations(derived classes or classes behind
		the interface) access and use the implementations.

		in the example below, the interface class for AccountStorage contains
		public pure virtual methods that decide how you're going to interacting
		with whatever way the developer chooses to implement accountstorage.

		the methods are
			public
				because then they'll be available to be called from outside
				the implementation/derived class, which is what you would
				want from an interface that's between the world and the implementation
			virtual
				to indicate that the method can be overwritten(override) in
				derived classes
			pure virtual : virtual func() = 0;(the = 0; part)
				this requires the derived class to override the function
				and the compiler will not allow instantiation of a class
				with a pure virtual method in it.

				meaning the derived class has to override and implement
				these functions.

		last bit: the important bit is that you can a pointer(or reference)
		of the type of the base class but it will also accept a target
		that is derived from the base class.

		So a bank may have a pointer to an interface for accountstorage
		that can take other implementations of that interface.

		Interfaces encourage encapsulation and loosely coupled design. With
		simple, focused interfaces, you can encourage code reuse by making
		your code portable across projects.      - C++ Crash Course p.147
*/

class IAccountStorage
{
	public:
		virtual void AddAccount(std::string id) = 0;
		virtual Account *GetAccount(std::string id) = 0;
};

#endif
