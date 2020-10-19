#include <stdio.h>
#include <stdbool.h>





// function prototypes
void print_int(int number);
void print_array(int* arr, int arr_size);
bool over18(int age);



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

	// new function pointer
	void (*func2_ptr)(int*, int) = &print_array;

	// calling new function pointer
	(*func2_ptr)(arr, sizeof(arr) / sizeof(int));

	// declaring boolean function pointer
	bool (*func3_ptr)(int) = &over18;

	// declaring & initalizing int
	int age = 0;

	// enter age
	printf("\nEnter age: ");
	scanf("%d", &age);

	// calling function pointer to check condition
	if ((*func3_ptr)(age)) printf("\nOver 18");
	else printf("\n18 or under");

}
void print_int(int number)
{
	printf("\nprinting int: %d", number);
}
void print_array(int* arr, int arr_size)
{
	printf("\n");
	for (int index = 0; index < arr_size; index++, arr++) printf("%d ", *arr);
}
bool over18(int age)
{
	if (age > 18) return true;
	else return false;
}