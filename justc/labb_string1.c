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
		/*
			Loops through the string in reverse, index(start of loop) is set at the end of the string(strlen(b))
			then is decremented.
		*/
		if (b[index] == 'a') // if element of b in position [index] == 'a'
		{
			printf("sista a har index: %d\n", index);
			break; // break out of the for loop when first "a" is found
		}
	}
	for (int index = 0; index < strlen(b); index++)
	{
		if (b[index] == 'C')
			printf("C har positionen: %d\n", index);
	}
	printf("Length of string is: %d", strlen(b)); // strlen == string length

	char temp[strlen(b)];
	strcpy(temp, b);
	char delimiter[] = " ";

	char* word = strtok(temp, delimiter);
	/*
		We're going to be using strtok() which modifies the string it's working on, since we still
		need to use our string later. We create a temporary string "char temp[strlen(b)]" to store
		a copy of the string which we'll modify instead.

		strcpy(temp,b) is a function that copies(string copy) string "b" onto string "temp". Works
		like "temp = b" in Python.

		char* word is a pointer to a kind of substring created in temp by strtok(). I feel kinda
		guilty using a pointer since we won't be getting to them till next week I think?

		But basiclly strtok loops through the string to the first occurence of the delimiter you
		passed in. Replaces that delimiter with a '\0' which when the pointer is put at the first
		letter will fool it into thinking the string ends at the first '\0' then it returns the
		pointer/first_string/word.

		strtok then repeats this process for the next occurence of the delimiter, putting the pointer
		at the position just after the last place it found a delimiter.
		*/
	while (word) // strtok returns NULL when it runs out of string to loop through. NULL == False, not NULL == true... kinda
	{
		print("%s\n", word); // prints whatever the pointer is pointing to in string format.
		word = strtok(NULL, delimiter);
		/*
			Key part of using strtok() is that it only returns one "word" per run/call so it needs
			to be called several times for this string which is why it is in a while() loop

			Now why is the first argument "NULL"?
			strtok() remembers the last string it worked on and will keep working on it whenever
			you call it UNLESS you send in a new string to work on. NULL is just a way to let
			strtok() know that it should be keep working on whatever string it already has.
		*/
	}

	// NOT FINISHED YET
	// just been moved to correct labb/file
}