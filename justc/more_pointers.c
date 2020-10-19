#include <stdio.h>






void print_int(int number);



int main(void)
{
	// declares integer normal variable
	int number = 0;
	// declares integer pointer and assigns it to the address(box) of number(think of it like left = "int foo(int* int_ptr)" and right = "foo(&number)")
	int* int_ptr = &number;

	// access what "int_ptr" is pointing to and increment it
	(*int_ptr)++;
	printf("\nNumber: %d", number);
	printf("\nPtr dereferenced: %d", *int_ptr); // print what int_ptr is pointing to use using derefence operator "*"

	// declares and initializes int array
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };

	// points the pointer at the array
	int_ptr = arr;

	// loops through the array using the pointer
	for (int index = 0; index < sizeof(arr) / sizeof(int); index++, int_ptr++)
		printf("\nValue %d is: %d", index, *int_ptr);

	// declares and initializes string
	char string[] = "Wabbajack";

	// points pointer to string
	char* char_ptr = string;

	// just adds a newline char to terminal
	printf("\n");

	// loops through string using the pointer to it
	for (; *char_ptr != '\0'; char_ptr++) printf("%c", *char_ptr);

	// declaring function pointer to function "print_int"
	void (*func_ptr)(int) = &print_int;

	// calling function "print_int" via pointer with function argument "10"
	(*func_ptr)(10);

}
void print_int(int number)
{
	printf("\nprinting int: %d", number);
}
