#include <stdio.h>
#include <stdlib.h> // included for calloc()
#include <limits.h>

#define ARR_LEN 100

void labb1(void);
void labb2(void);
void labb2dynamic(void);


void main(void)
{
	labb2dynamic();
}
void labb1(void)
/*
	Create a program where the user is asked input a number 4 times
		Save all values in an array
		Loop through the array and find the largest value
		Print the result on the screen
*/
{
	int values[4] = { 0 }; // automatically zeroes the rest of the array
	int max = INT_MIN; // sets max to lowest possible int value
	for (int index = 0; index < 4; index++)
	{
		printf("\nEnter number %d: ", index);
		scanf("%d", &values[index]);
		if (values[index] > max) max = values[index]; // check if input value is larger than max
	}
	for (int index = 0; index < 4; index++) printf("\nValue %d is: %d", index, values[index]);
	printf("\nMax is %d: ", max);
}
void labb2(void)
/*
	Same as previous labb but this time ask the user the amount of numbers to input
*/
{
	int values[ARR_LEN] = { 0 }; // automatically zeroes the rest of the array
	int max = INT_MIN; // sets max to lowest possible int value
	int nr_values = 0; // variable for amount of values to enter

	printf("\nEnter amount of numbers to enter: ");
	scanf("%d", &nr_values); // assigns number of values to enter

	for (int index = 0; index < nr_values; index++) // for loop second condition. while less than nr values to enter
	{
		printf("\nEnter number %d: ", index);
		scanf("%d", &values[index]);
		if (values[index] > max) max = values[index]; // check if input value is larger than max
	}
	for (int index = 0; index < 4; index++) printf("\nValue %d is: %d", index, values[index]);
	printf("\nMax is %d: ", max);
}
void labb2dynamic(void)
/*
	labb 2 but with a dynamic array
*/
{
	int nr_values = 0;
	int max = INT_MIN;

	printf("\nEnter nr of values to enter: ");
	scanf("%d", &nr_values);

	int* dynamic; // declares a pointer
	dynamic = calloc(nr_values, sizeof(int));
	/*
		calloc allocates memory(boxes or size of a box) of nr_values * sizeof(int)
		so it pretty much declares int (variable name) nr_value times.

		calloc also initializes the memory it created and sets them to zero unlike
		malloc()

		then we assign the POINTER dynamic to that memory space, pointing at the first
		(int) memory slot created
	*/

	for (int index = 0; index < nr_values; index++)
	{
		/*
			Here we start assigning input values the allocated memory slots
			and we can do it just as if it was an array(or maybe an array
			is just really a pointer? maybe that's why you don't need
			to send it's adress when used as a function argument?
		*/
		printf("\nEnter value nr %d: ", index + 1);
		scanf("%d", &dynamic[index]);
		if (dynamic[index] > max) max = dynamic[index];
	}

	for (int index = 0; index < nr_values; index++) printf("\nValue %d is: %d", index, dynamic[index]);
	printf("\nMax is %d: ", max);
	free(dynamic); // de-allocates memory
}