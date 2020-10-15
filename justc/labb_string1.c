#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 100

void labb1(void);
void labb2(void);
void labb3(void);
void labb4(void);
void labb5(void);
void labb6(void);
void labb7(void);





void main(void)
{
	labb1();
	labb2();
	labb3();
	labb4();
	labb5();
	labb6();
	labb7();

}
void labb1(void)
/*
	Ask user to input 3 strings.
		Add strings and print them to screen.
*/
{
	char string1[3][STRLEN]; // 2-dimensional array of 3 rows and STRLEN columns(or 3 strings of length STRLEN)

	for (int row = 0; row < 3; row++)
	{
		printf("Enter string %d: ", row);
		if (scanf("%s", string1[row]) > STRLEN) // if the amount of characters scanf read is less than STRLEN
		{
			printf("\nString too long.\nTry again(less than 100 characters).");
			row--;
		}
	}
	char added_strings[STRLEN * 3] = "";
	for (int row = 0; row < 3; row++)
	{
		strcat(added_strings, string1[row]);
	}
	printf("\nconcatenated: %s", added_strings);
}
void labb2(void)
/*
	Given a string initiated with the text "Hello, world!"
		a. Find the position of the letter "w"
		b. Print ut the position of "w"
*/
{
	char hello_world[] = "Hello, world!";

	for (int index = 0; index < strlen(hello_world); index++)
		if (hello_world[index] == 'w') printf("\nPosition is: %d", index);
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
	char b[] = "I am a C hacker";

	for (int index = strlen(b); index >= 0; index--)
	{
		/*
			Loops through the string in reverse, index(start of loop) is set at the end of the string(strlen(b))
			then is decremented.
		*/
		if (b[index] == 'a') // if element of b in position [index] == 'a'
		{
			printf("\nsista a har index: %d", index);
			break; // break out of the for loop when first "a" is found
		}
	}
	for (int index = 0; index < strlen(b); index++)
	{
		if (b[index] == 'C')
			printf("\nC har positionen: %d", index);
	}
	printf("\nLength of string is: %d", strlen(b)); // strlen == string length

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
		printf("\n%s", word); // prints whatever the pointer is pointing to in string format.
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
void labb4(void)
/*
	Given a string initiated with the name "kurt andersson"
		Write code that capitalizes the first and last name
		Result should be "Kurt Andersson"
*/
{
	char name[] = "kurt andersson";
	int capitalize = 1;
	for (int index = 0; index < strlen(name); index++)
	{
		if (capitalize) name[index] = toupper(name[index]);
		if (name[index] == ' ') capitalize = 1;
		else capitalize = 0;
	}
	printf("\n%s", name);

}
void labb5(void)
/*
	Given a string initialized with "this is the string you will change"
		Replace all the space " " character with "*"
		Calculate the amount of "*" characters in the string
*/
{
	char string[] = "this is the string you will change";
	int count = 0;
	for (int index = 0; index < strlen(string); index++)
	{
		if (string[index] == '*') count++;
		if (string[index] == ' ')
		{
			string[index] = '*';
			count++;
		}
	}
	printf("\nModified string: %s\tcount of * chars: %d", string, count);
}
void labb6(void)
/*
	Given a string set to ”one,two,three,four,five,six,seven”.
		create a 2-dimensional array
		split the string at ","
		put each number into a separate column in the array.
*/
{
	char string[] = "one,two,three,four,five,six,seven";
	char multidimensional[7][STRLEN];

	char delimiter[] = ",";

	char* number = strtok(string, delimiter);

	for (int index = 0; index < 7; index++)
	{
		strcpy(multidimensional[index], number);
		number = strtok(NULL, delimiter);
	}
	for (int index = 0; index < 7; index++) printf("\n%s", multidimensional[index]);
}
void labb7(void)
/*
	Ask user to input a mail address
		Program will check that input is correct.
		Is correct if address contains: one "@" and one "." followed by at least 2 characters
		Notify user if address is correct.
*/
{
	char mail_address[STRLEN];

	do
	{
		printf("\nEnter mail address: ");
		if (scanf(" %s", mail_address) < STRLEN) break;
	} while (1);

	int foundat = 0; // shitty variable names
	int foundpunctuation = 0;

	for (int index = 0; index < strlen(mail_address); index++)
	{
		if (mail_address[index] == '@') foundat++;
		if (mail_address[index] == '.') foundpunctuation++;
		if (foundpunctuation) foundpunctuation++;
	}
	if (foundat && foundpunctuation > 3) printf("\nAddress is correct");
	else printf("\nIncorrect Address");
}