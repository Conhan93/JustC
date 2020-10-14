#include <stdio.h>
#include <string.h>



int main(void)
{

}
void labb1(void)
/*
	Write a program that'll print ut the numbers 1-10 in your terminal.
		Solve using a for loop.
*/
{
	/*
		The first argument is setting variables that'll be in the scope of the for loop
		The second argument is the condition that the for loop checks everytime it runs
		the third is what the for loop does at the end of its run(increments number in this case)
	*/
	for (int number = 0; number <= 10; number++) // for loops have a tiny invisible code block after them, one execution long
		printf("%d ", number); // so you don't have to put braces here if the for loop just does one thing
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
	printf("Enter numbers in format(tal1,tal2): ");
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
void labb3(void) // this is in the wrong labb!!! string labb not loop labb
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

	char temp[] = b;
	char delimiter[] = " ";

	char* word = strtok(temp, delimiter);
	while (word != NULL)
	{
		print("%s\n", word);
		word = strtok(NULL, delimiter);
	}
}