#include <stdio.h>
#include <limits.h> // INT_MIN from here
#include <stdlib.h> // included for calloc()
#include <float.h>
#include <string.h>

#define ARR_LEN 100 // used to set the length of the array
#define ISO_LEN 11

// struct used for labb5b
typedef struct
{
	float temperature;
	char date[ISO_LEN];
} Measurement;

Measurement CreateMeasurement(float temperature, char date[]); // function used for labb5b
void labb1(void);
void labb2(void);
void labb2dynamic(void); // labb 2 but with dynamic array
void labb3(void);
void labb4(void);
void labb5(void);
void labb5a(void);
void labb5b(void);



void main(void)
{
	labb1();
	labb2();
	labb2dynamic();
	labb3();
	labb4();
	labb5();
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

	/*
		The maximum size of the array is ARR_LEN == 100, you can't get
		away from having fixed sizes for arrays unless you make a
		dynamic array --- might make one here just to demonstrate
		though it'll involve pointers and calls of malloc()
	*/

	printf("\nEnter amount of numbers to enter: ");
	scanf("%d", &nr_values); // assigns number of values to enter

	for (int index = 0; index < nr_values; index++) // for loop second condition. while less than nr values to enter
	{
		printf("\nEnter number %d: ", index);
		scanf("%d", &values[index]);
		if (values[index] > max) max = values[index]; // check if input value is larger than max
	}
	for (int index = 0; index < nr_values; index++) printf("\nValue %d is: %d", index, values[index]);
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
			and we can do it just as if it was an array and use indexing
			to iterate through the memory slots!
		*/
		printf("\nEnter value nr %d: ", index + 1);
		scanf("%d", &dynamic[index]);
		if (dynamic[index] > max) max = dynamic[index];
	}

	for (int index = 0; index < nr_values; index++) printf("\nValue %d is: %d", index, dynamic[index]);
	printf("\nMax is %d: ", max);
	free(dynamic); // de-allocates memory
}
void labb3(void)
/*
	Create an array and initialize it with 5 integers
		Replace all odd numbers with 0
		Print array to screen
*/
{
	int array[] = { 1,2,3,4,5 };
	for (int index = 0; index < 5; index++)
		if (array[index] % 2) array[index] = 0;
	for (int index = 0; index < 5; index++) printf("\n%d", array[index]);
}
void labb4(void)
/*
	Create an array to hold temperature readings
		User gets to enter amount of readings to enter.
		User gets to enter temperature readings in decimal
		Print values, average and max
*/
{
	float temperatures[ARR_LEN] = { 0 };

	int nr_values = 0;
	float maxi = FLT_MIN, sum = 0;

	printf("\nEnter nr values to enter: ");
	scanf("%d%*c", &nr_values);

	for (int index = 0; index < nr_values; index++)
	{
		printf("\nEnter temperature value nr %d: ", index);
		scanf("%f%*c", &temperatures[index]);

		if (temperatures[index] > maxi) maxi = temperatures[index];
		sum += temperatures[index];
	}
	for (int index = 0; index < nr_values; index++)
		printf("%.2f ", temperatures[index]);
	printf("\nAverage: %.2f , max: %.2f", sum / nr_values, maxi);
}
void labb5(void)
/*
	The same as labb 4 but in addition to temperature input
	you'll ask for date input too
		a. solve using two arrays
		b. solve using struct
*/
{
	labb5a();
	labb5b();
}
void labb5a(void)
{
	float temperatures[ARR_LEN] = { 0 };
	char dates[ARR_LEN][ISO_LEN];

	int nr_values = 0;
	float max_temp = FLT_MIN, sum = 0;

	printf("\nEnter nr values to enter: ");
	scanf("%d%*c", &nr_values);

	for (int index = 0; index < nr_values; index++)
	{
		printf("\nEnter measurement date(dd-mm-yyyy): ");
		scanf("%s", dates[index]);
		printf("\nEnter temperature value nr %d: ", index);
		scanf(" %f%*c", &temperatures[index]);

		if (temperatures[index] > max_temp) max_temp = temperatures[index];
		sum += temperatures[index];
	}
	printf("\nDates\t\tMeasurements");
	for (int index = 0; index < nr_values; index++)
		printf("\n%s\t%.2f ", dates[index], temperatures[index]);
	printf("\nAverage: %.2f , max: %.2f", sum / nr_values, max_temp);
}
void labb5b(void)
{
	Measurement measurements[ARR_LEN];
	char date[ISO_LEN] = "";
	float temperature = 0;

	int nr_values = 0;
	float max_temp = FLT_MIN, sum = 0;

	printf("\nEnter nr values to enter: ");
	scanf("%d", &nr_values);

	for (int index = 0; index < nr_values; index++)
	{
		printf("\nEnter measurement date(dd-mm-yyyy): ");
		scanf("%s", date);
		printf("\nEnter temperature value nr %d: ", index);
		scanf("%f", &temperature);

		if (temperature > max_temp) max_temp = temperature;
		sum += temperature;
		measurements[index] = CreateMeasurement(temperature, date);
	}
	printf("\nDates\t\tMeasurements");
	for (int index = 0; index < nr_values; index++)
		printf("\n%s\t%.2f ", measurements[index].date, measurements[index].temperature);
	printf("\nAverage: %.2f , max: %.2f", sum / nr_values, max_temp);
}
Measurement CreateMeasurement(float temperature, char date[])
{
	Measurement measurement;
	measurement.temperature = temperature;
	strcpy(measurement.date, date);

	return measurement;
}
