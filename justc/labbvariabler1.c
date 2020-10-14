#include <stdio.h>
#include <stdlib.h>
/*
	<stdlib> = standard library
	Used to get access to abs(x) function which returns the absolute value(positive value) of x
*/

#define STRLEN 100
/*
	Defines or declares a macro of 100(int) which we use to set the size
	of the strings we are going to use

	Macros are written all upper case MACROS
*/



void labb1(void);
void labb2(void);
void labb3(void);
void labb4(void);
void labb5(void);
void labb6(void);
void labb7(void);
void labb8(void);
void newlabb(void); // Just prints two newlines



int main(void)
{
	// labbs in sequence
	labb1();
	labb2();
	labb3();
	labb4();
	labb5();
	labb6();
	labb7();
	labb8();
}

void labb1(void) // Print hello + your name
{
	newlabb();
	char namn[STRLEN] = "Enter your name here";
	/*
		Declares an array with the length of STRLEN which we defined to 100
		then we initialize the array to the string literal "enter your name here"
	*/

	printf("Hello %s", namn);
	/*
		Prints ut the string "hello %s" where "%s" is a format specifier for a "string"/char array.
		printf puts the name array/string into the place where we put our format specifier "%s".
	*/

}

void labb2(void)
/*
	Create an application
		a. Create a string namn with the text "enter name here"
		b. Create an int with your age
		c. Then print a string that says "my name is x and i am y years old.
*/
{
	newlabb();
	char namn[STRLEN] = "Enter name here";
	int age = 0; // Enter name here, good praxis to initiate your variables

	printf("My name is %s and I am %d years old", namn, age); // Trivia : printf = print format -> prints formatted string
	/*
		Prints the string with variables placed in where we placed format specifiers
		in order they're entered
		so "%s... %d" , namn(string), age(integer).
	*/
}

void labb3(void)
/*
	Create an application where the user enters first and lastname
		a. Print "Enter your name" and save the name in a variable
		b. Await input on the same line(no newline)
		c. Repeat for lastname
		d. Print the names in reverse order
		e. Make sure output looks like this .(see stefans teeny tiny picture!)
*/
{
	newlabb();
	char fornamn[STRLEN], efternamn[STRLEN];
	printf("enter firstname: ");
	scanf("%s", fornamn);
	/*
		No need for address-of operator "&" for arrays as they already
		use "pass-by-reference" instead of pass-by-value like most basic
		data types.
	*/
	printf("\nenter lastname: ");
	scanf("%s", efternamn);
	printf("\nYour name is %s, %s", efternamn, fornamn); // order of variables and specifiers must match

}
void labb4(void)
/*
	Write an application where the user is asked to enter two numbers
		a. Print enter first number: 
		b. Save value in a variable
		c. Print enter second number:
		d. Save this value in a variable too(shocker).
		e. print "the sum is (sum)"
*/
{
	newlabb();
	int tal1 = 0, tal2 = 0; // possible to declare and initiate several variables on the same row

	printf("Enter first number: ");
	scanf("%d", &tal1);
	/*
		basic data types need the address-of operator "&" to be able to be "passed by reference"
		which they need to be if you want to change them when they're passed to functions
		like how you want to change the value of tal1 when passing it to scanf()
	*/
	printf("\nEnter second number: ");
	scanf("%d", &tal2);
	printf("\nThe sum is: %d", tal1 + tal2);
}

void labb5(void)
/*
	Write a program that takes the users birth year and prints their age
		a. Take birth year and calculate age
		b. Print to screen - "Your age is: (age)"
		c. Try setting todays date(year) in a variable and use this to calculate age
*/
{
	newlabb();
	int date_of_birth = 0, current_year = 2020;
	printf("enter birth year: ");
	scanf("%d", &date_of_birth);
	printf("\nYou are %d years old", current_year - date_of_birth);
}

void labb6(void)
/*
	Enter two numbers and print their average, sum and difference
		a.Print "Enter first number" and save in a variable
		b.Print "Enter second number" and save in a variable
		c.calculate average, sum and difference
		d. display calculated values
*/
{
	newlabb();
	int tal1, tal2;
	printf("Enter first number: ");
	scanf("%d", &tal1);
	printf("\nEnter second number: ");
	scanf("%d", &tal2);
	printf("\nAverage: %.2f\nSum: %d\nDifference: %d", (float)(tal1 + tal2) / 2, tal1 + tal2, abs(tal1 - tal2));
	/*
		Alright here's a few things.
			"Average: %.2f" here our format specifiers says we want to print a float number with 2 decimal
			points, the ".2" specifies the number of decimal points to print
			"(float)" is explicit casting of the calculation (tal1 + tal2)/2 from int to float.
			had we not casted the calculation it would have stayed an int and rounded to the nearest whole number.
			And we would have lost information. ex: 3/4 evaluates to a fraction 0.75 != integer(whole number)
			"abs(tal1-tal2)" we enter the difference between the numbers into "abs()" from <stdlib.h>
			which returns the absolute value(positive value) of its argument.
	*/
}
void labb7(void)
/*
	Ask the user to enter an amount
		add 25% sales tax to the sum then print the sum onscreen
*/
{
	newlabb();
	int summa = 0;
	printf("Enter amount: ");
	scanf("%d", &summa);
	printf("with tax: %.2f", summa * 1.25);
}
void labb8(void)
/*
	Create a program that takes minutes as input and prints the input in hours and minutes
		a. print "Enter minutes"
		b. Recieve input and save in variable
		c. convert to hours and minutes
		d. Print - "this is  .. hours and … minutes"
*/
{
	newlabb();
	int minutes = 0, hours = 0;
	do
	{
		printf("Enter minutes: ");
		scanf("%d", &minutes);
	} while (minutes < 60);
	hours = minutes / 60; // minuter divided by the amount of minutes in an hour = multiples of hours
	minutes = minutes % 60; // modul, rest division(maths)
	printf("This is  %d hours and %d minutes", hours, minutes);
}
void newlabb(void)
{
	printf("\n\n");
}