#include <stdio.h>
#include <string.h>










void main(void)
{


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

	char temp[strlen(b)];
	strcpy(temp, b);
	char delimiter[] = " ";

	char* word = strtok(temp, delimiter);
	while (word)
	{
		print("%s\n", word);
		word = strtok(NULL, delimiter);
	}

	// NOT FINISHED YET
	// just been moved to correct labb/file
}