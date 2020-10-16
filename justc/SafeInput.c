#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h> // this is the header containing macros like LONG_MIN
#include <stdlib.h>
#include "safeinput.h"

bool GetInputInt(char* prompt, int* value)
{
	/*
		the little * indicates that the variables are using "pass-by-reference"
		which means we give the function access to the "boxes" the values are stored
		in so they can be changed.

		basiclly if you have a value you want to change when passed into a function
		you use pass-by-reference otherwise they're passed by value which means
		you're working with a copy of the value instead of the actual value

	*/
	char buff[255]; // creates a string which Getinput will read on to
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK) // runs getinput() and returns false if it fails
		return false;
	long l = LONG_MIN; // sets l to the lowest possible number

	l = strtol(buff, NULL, 10);
	if (l == LONG_MIN) return false;
	*value = l;
	return true;
	/*
		Here strtol(string to long) converts buffer to a long integer
		to check if conversion was succesfull(I think) he checks if l
		has been changed from LONG_MIN and if it has he assigns *value
		the converted value(l)

		then returns true to report sucessfull operation
		*/
}


bool GetInputFloat(char* prompt, float* value)
{
	char buff[255]; // creates a string which Getinput will read on to
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK) // runs getinput() and returns false if it fails
		return false;
	float l = -100000000.0f; // really small float number
	
	/*
		I just checked and I think Stefan wanted to use a Macro here like for
		LONG_MIN but couldn't find it because the macro for the smallest float
		isn't in "limits.h" but in "float.h" so he just picked a really small
		number instead
	*/

	l = strtof(buff, NULL, 10);
	if (l == -100000000.0f) return false;
	*value = l;
	/*
		This is basiclly the same as for GetInputInt but instead of LONG_MIN
		he uses -100000000.0f and the function strtof(string to float)
	*/
	return true;
}


bool GetInputChar(char* prompt, char* value)
{
	char buff[255]; // creates a string which Getinput will read on to
	if (GetInput(prompt, buff, sizeof(buff)) != INPUT_RESULT_OK) // runs getinput() and returns false if it fails
		return false;
	*value = buff[0]; // changes Value to the char at [0](first element in string)
	return true; // returns true(so you can check if function was sucessfull
}

// the return is a typedef created in the header file(type deffed Enumeration)
INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize)
{
	/*
		The arguments are
			Prompt - this will be printed out when function is called
			The code block directly below just checks if prompt exists
			basiclly.
			Buff - This is the variable passed to the function that
			the input will be stored in(like the variable in scanf("whatever", &variable))
			maxSize - this is the maximum amount of characters that will be read
	*/

	if (prompt != NULL && strlen(prompt) > 0) // is there a prompt? if yes then run code block below
	{
		printf("%s", prompt); // print prompt
	}
	if (fgets(buff, maxSize, stdin) == NULL)
		return INPUT_RESULT_NO_INPUT;
	/*
		in the if statement above, Bad Boi Stefan actually uses a deprecated(outdated) input function
		like scanf() to read input from the "standard input stream" where
		buff - is the variable where input is stored.
		maxSize - is the same as above.
		stdin - is the input stream(what you type into your terminal)

		the if statement checks if the function fails and returns an integer(defined
		by enum in header file).
		Also worth noting that the function actually runs even if it is in an if statement
		so it still reads into buff even if it doesn't trigger "INPUT_RESULT_NO_INPUT"
		and continues onto the code below
	*/

	// These are Stefans comments
	// If it was too long, there'll be no newline. In that case, we flush
	// to end of line so that excess doesn't affect the next call.


	if (buff[strlen(buff) - 1] != '\n') { // checks if buff doesn't end with a newline character(means there's a problem)
		int extra = 0;
		char ch;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			/*
				So in the while statement condition check above there's two things happening.
					1. The last entered character is read, stored in "ch" and checked to see
					   that it is NOT a newline character.
					2. the value stored in ch is checked to see if it is NOT an EOF character
					   EOF(End Of File) character. Which would indicate an error
					   which runs the code below, (extra = 1)
			*/
			extra = 1;
		return (extra == 1) ? INPUT_RESULT_TOO_LONG : INPUT_RESULT_OK;
		/*
			This last bit in the return statement is known as a "Ternary Operator"
			it works like an if-else statement in the form "result = (condition) ? (do this if condition is true) : (this if condition false);"

		*/
	}

	// Otherwise remove newline and give string back to caller. -- Stefan
	buff[strlen(buff) - 1] = '\0'; // adds an EOF(End Of File) character to the string to close it
	return INPUT_RESULT_OK; // reports function as sucessfull
}
