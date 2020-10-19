#include <stdio.h>

void labb1(void);
void labb1function(int* change_me);
void labb2(void);
void labb3(void);
void foo1(int xval);
void foo2(int dummy);


int main(void)
{
	labb1();
	labb2();
	labb3();
}
void labb1(void)
/*
	Create a function SetAsZeroIfLargerThan10
		that takes an int as argument.
		changes the value of that int to zero if int > 10
*/
{
	int whatever = 0;

	printf("\nEnter value: ");
	scanf("%d", &whatever);

	labb1function(&whatever);
	/*
		To be able to change a variable inside another function you have to pass a reference(pass-by-reference) to the value.
		Otherwise you will only provide the function with a copy of the variable to work with, meaning it won't change the
		variable outside of the function.

		Using the box example. Lets say you declare a variable and initialize it(creating a box and putting something in it).
		when you try to pass that variable directly, you're only creating a copy of the box and its content to the function.

		To actually change the value of the original declared box you need to pass the location of that box to the function
		so it'll know what to change(also what type of box, int, char).
		This is done by providing the function with the address of where that variable was declared
		using the address-of operator "&" <-- this is not a pointer, it's simply the address

		to be able to use that address though you need to have a pointer pointing to it(a reference) which you create in your
		functionargument.
		ex. we want to change the value of "whatever" in "labb1function" so we need to pass the address to the function.
		we use "&whatever" in the function call to send the address to the function.
		in the function declaration "void labb1function(int* change_me)" we've declared a int pointer to recieve that address.
		so "int* change_me" now points to the address provided by "&whatever".

		the next step is accessing that address through the pointer created and changing the value located at the address.
		this is done through using a dereference operator "*".
		
		so using the dereference operator "*" on the int pointer "change_me" like "*change_me" allows us to change the value of
		"whatever" setting it to 0.
		*/

	printf("\nNew value: %d", whatever);
}
void labb1function(int* change_me)
{	// accessing value of the address "change_me" is pointing to
	if (*change_me > 10) (*change_me) = 0;
}
void labb2(void)
/*
	2. Pointers

	int y=1;

	 print the address and value of y here

	printf("%p   %d\n", &y, y);


	Write a short C program that declaresand initializes(to any value you like) a
	double, an int, and a char.Next declareand initialize a pointer to each of
	the three variables.Your program should then print the address of, and value
	stored in, and the memory size(in bytes) of each of the six variables.
	Use the “0x% x” formatting specifier to print addresses in hexadecimal.You
	should see addresses that look something like this: "0xbfe55918".The initial
	characters "0x" tell you that hexadecimal notation is being used; the remainder
	of the digits give the address itself.
	Use the sizeof operator to determine the
	memory size allocated for each variable.
	Sample output :
	The address of char ___ is 0x_______
	The address of int ___ is 0x_______
	The address of double ___ is 0x_______
	The address of char* ___ is 0x_______
	The address of int* ___ is 0x_______
	The address of double* ___ is 0x_______
	The value of char ___ is _______
	The value of int ___ is _______
	The value of double ___ is _______
	The value of char* ___ is 0x_______
	The value of int* ___ is 0x_______
	The value of double* ___ is 0x_______
	The size of char is _______ bytes
	The size of int is _______ bytes
	The size of double is _______ bytes
	The size of char* is _______ bytes
	The size of int* is _______ bytes
	The size of double* is _______ bytes


*/
{
	int integer = 5;
	double dub_fx = 25;
	char charizard = 'j';

	/*
		Declaring variables and initializing them. these are automaticlly given
		addresses(boxes)
	*/

	int* int_ptr = &integer;
	double* dub_ptr = &dub_fx;
	char* char_ptr = &charizard;

	/*
		declaring pointers and initializing them with the addresses
		of the previously declared variables.

		using "&" address-of operator to access the addresses of those variables.
	*/
	

	// values
	printf("\nThe address of char %c is 0x%x", charizard, char_ptr);
	printf("\nThe address of int %d is 0x%x", integer, int_ptr);
	printf("\nThe address of double %.2lf is 0x%x", dub_fx, dub_ptr);

	// accessing values of pointers by use of "*" dereference
	printf("\nThe address of char* %c is 0x%x", *char_ptr, char_ptr);
	printf("\nThe address of int* %d is 0x%x", *int_ptr, int_ptr);
	printf("\nThe address of double* %.2lf is 0x%x", *dub_ptr, dub_ptr);

	// value and values of pointers("*")
	printf("\nThe value of char %c is %c", charizard, *char_ptr);
	printf("\nThe value of int %d is %d", integer, *int_ptr);
	printf("\nThe value of double %.2lf is %.2lf", dub_fx, *dub_ptr);

	// value of pointer and value of pointer
	printf("\nThe value of char* %c is %c", *char_ptr, *char_ptr);
	printf("\nThe value of int* %d is %d", *int_ptr, *int_ptr);
	printf("\nThe value of double* %.2lf is %.2lf", *dub_ptr, *dub_ptr);

	// size of basic data types
	printf("\nThe size of char is %d bytes = %d bits", sizeof(charizard), sizeof(charizard) * 8);
	printf("\nThe size of int is %d bytes = %d bits", sizeof(integer), sizeof(integer) * 8);
	printf("\nThe size of double is %d bytes = %d bits", sizeof(dub_fx), sizeof(dub_fx) * 8);

	// size of pointers, pointers are just addresses
	printf("\nThe size of char* is %d bytes = %d bits", sizeof(char_ptr), sizeof(char_ptr) * 8);
	printf("\nThe size of int* is %d bytes = %d bits", sizeof(int_ptr), sizeof(int_ptr) * 8);
	printf("\nThe size of double* is %d bytes = %d bits", sizeof(dub_ptr), sizeof(dub_ptr) * 8);


}
void labb3(void)
/*
	3. Pointers and stack

	Find out (add code to print out) the address of the variable x in foo1, and the
	variable y in foo2. What do you notice? Can you explain this?

	#include <stdio.h>
	void foo1(int xval)
	{
	 int x;
	 x = xval;
	  print the address and value of x here
	}
	void foo2(int dummy)
	{
		int y;

		 print the address and value of y here
	}
	int main()
	{
		foo1(7);
		foo2(11);
		return 0;
	}
*/
{
	int x = 0;
	printf("\nValue of x in ""main"" is %d, address: 0x%x ", x, &x);
	foo1(x);
	foo2(x);
	/*
		The addresses for the variables in foo1() and foo2() are the same
		because they occupy the same in the stack.

		foo1 is created in the next position in the stack, int x is declared at that position
		foo1 is finished executing and is destroyed, freeing that position in the stack
		foo2 is created in the next position in the stack which happens to be in the same place
		as foo1 was created.

		also both variables in foo1 and foo2 are the first variables declared so they also share
		the same space in their functions

	*/
}
void foo1(int xval)
{
	int x;
	x = xval;
	//print the addressand value of x here
	printf("\nValue of x in foo1 is %d, address: 0x%x ", x, &x);
}
void foo2(int dummy)
{
	int y;

	//print the addressand value of y here
	printf("\nValue of y in foo2 is %d, address: 0x%x ", y, &y);
}