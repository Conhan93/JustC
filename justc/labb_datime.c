#include <stdio.h>
#include <time.h>






void main(void)
{

}
void labb1(void)
/*
	Create an a program that finds current date, time and prints out:
		Expected Output:
		Complete date: 2019-09-06 12:15:00
		Short Date: 2019-09-06
*/
{
	struct tm* time_ptr;
	time_t time_struct;
	char time_string[40];

	// initializes time_struct
	time_struct = time(NULL);

	// initalizes pointer
	time_ptr = localtime(&time_struct);

	// formats string for complete form
	strftime(time_string, 40, "%d-%m-%Y %H:%M:%S", time_ptr);

	// complete form
	printf("Complete date: %s", time_string);

	// formats string for short form
	strftime(time_string, 40, "%d-%m-%Y", time_ptr);

	printf("\nShort Date: %s", time_string);

}