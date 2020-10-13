#include <stdio.h>
#include <string.h>


#define LABB1 11


int main(void)
{

}
void labb1(void)
/*
	Write a program that'll print ut the numbers 1-10 in your terminal.
		Solve using a for loop.
*/
{
	int numbers[LABB1] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

	for (int index = 0; index < LABB1; index++)
	{
		printf("%d, ", numbers[index]);
	}
}
void labb2(void)
/*
	Write a program that lets the user enter two numbers.
		Let the program print out all the numbers
		between the entered numbers on screen(terminal)
		Solve using for loop
*/
{
	int tal1, tal2;
	printf("Mata in tal i format (tal1,tal2): ");
	scanf("%d,%d", &tal1, &tal2);
	if (tal1 < tal2)
	{
		for (int number = tal1; number <= tal2; number++)
			printf("%d", number);
	}
	else if (tal2 < tal1)
	{
		for (int number = tal2; number <= tal1; number++)
			printf("%d", number);
	}
	else printf("\nwtf");
}
void labb3(void)
/*	
	With a string variable like this b = "I am a C  hacker."
		a. Print ut the position of the last "a" --- Skriv ut vilken position sista a har 
		b. Print ut the position of "C" and the same time print out the lenght of the string. 
		c. Print out every word one seperate lines 
		d. Modify the string to "i Am A C hAcKeR"
*/
{
	char b[] = "I am a C  hacker";

	for (int index = strlen(b); index >= 0; index--)
	{
		if (b[index] == 'a')
		{
			printf("sista a har index: %d\n", index);
			break;
		}
	}
	for (int index = 0; index < strlen(b); index++)
	{
		if (b[index] == 'C')
			printf("C har positionen: %d\n", index);
	}
	printf("Langden av strangen ar: %d", strlen(b));

	// NOT FINISHED
}