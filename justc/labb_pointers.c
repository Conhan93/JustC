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
	printf("\nNew value: %d", whatever);
}
void labb1function(int* change_me)
{
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

	int* int_ptr = &integer;
	double* dub_ptr = &dub_fx;
	char* char_ptr = &charizard;


	printf("\nThe address of char %c is 0x%x", charizard, char_ptr);
	printf("\nThe address of int %d is 0x%x", integer, int_ptr);
	printf("\nThe address of double %.2lf is 0x%x", dub_fx, dub_ptr);

	printf("\nThe address of char* %c is 0x%x", *char_ptr, char_ptr);
	printf("\nThe address of int* %d is 0x%x", *int_ptr, int_ptr);
	printf("\nThe address of double* %.2lf is 0x%x", *dub_ptr, dub_ptr);

	printf("\nThe value of char %c is %c", charizard, *char_ptr);
	printf("\nThe value of int %d is %d", integer, *int_ptr);
	printf("\nThe value of double %.2lf is %.2lf", dub_fx, *dub_ptr);

	printf("\nThe value of char* %c is %c", *char_ptr, *char_ptr);
	printf("\nThe value of int* %d is %d", *int_ptr, *int_ptr);
	printf("\nThe value of double* %.2lf is %.2lf", *dub_ptr, *dub_ptr);

	printf("\nThe size of char is %d bytes = %d bits", sizeof(charizard), sizeof(charizard) * 8);
	printf("\nThe size of int is %d bytes = %d bits", sizeof(integer), sizeof(integer) * 8);
	printf("\nThe size of double is %d bytes = %d bits", sizeof(dub_fx), sizeof(dub_fx) * 8);

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