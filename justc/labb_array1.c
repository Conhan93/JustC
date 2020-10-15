#include <stdio.h>
#include <limits.h>

#define ARR_LEN 100


void main(void)
{

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