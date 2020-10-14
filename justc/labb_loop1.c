#include <stdio.h>
#include <string.h>

void labb1(void);
void labb2(void);
void labb3(void);
void labb4(void);
void labb5(void);
void labb6_a(void);
void labb6_b(void);
void labb6(void);

int main(void)
{
	labb1();
	labb2();
	labb3();
	labb4();
	labb5();
	labb6();
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
	printf("\nEnter numbers in format(tal1,tal2): ");
	scanf("%d,%d", &tal1, &tal2); // make sure to enter numbers in the given format!
	if (tal1 < tal2)
	{
		for (int number = tal1; number <= tal2; number++)
			printf("%d ", number);
	}
	else if (tal2 < tal1)
	{
		for (int number = tal2; number <= tal1; number++)
			printf("%d ", number);
	}
	else printf("\nwtf");
}
void labb3(void)
/*
	Create an application where:
		a. User inputs two numbers
		b. Print out sum of the numbers.
		c. Print a prompt asking user if they want to continue(y/n)?.
		d. If "y" - repeat a - c
		e. if "n" exit program
*/
{
	do
	{
		int number1 = 0, number2 = 0;
		char break_loop = 'n';
		printf("\nEnter first number: ");
		scanf("%d", &number1);
		printf("\nEnter second number: ");
		scanf("%d", &number2);
		printf("\nSum: %d", number1 + number2);
		printf("\nDo you want to continue(y/n)?: ");
		scanf("%*[\n]%c", &break_loop);
		if (break_loop == 'n') return;
	} while (1);

}
void labb4(void)
/*
	Ask user to input a number
		Save value in a variable and repeat the process 10 times.
		add saved input to a sum
		when done print "the sum is: (sum)"
*/
{
	int sum = 0; // needs to be declared outside the scope of for loop to persist.
	for (int iteration = 1; iteration <= 10; iteration++)
	{
		int input = 0;
		printf("\nEnter value %d: ", iteration);
		scanf("%d", &input);
		sum += input; // increments sum by value of input variable
	}
	printf("The sum is: %d", sum);
}
void labb5(void)
/*
	Create a program where user gets input a number
		Let the program print out all the numbers smaller than input but greater than 0.
		Solve using a loop
*/
{
	int input = 0;
	printf("\nEnter number: ");
	scanf("%d", &input);
	for (int number = input; number > 0; number--) // for loop in reverse
		printf("\n%d", number);
}
void labb6(void)
/*
	Create a loop that takes temperature inputs
		If the average of the last three inputs > 25 print "Alarm
		a) Solve using three variables
		b) Solve using an array
*/
{
	labb6_a(); // solved using three variables
	labb6_b(); // solved using array
}
void labb6_a(void)
{
	int temp1 = 0, temp2 = 0, temp3 = 0, iteration = 1;
	while (1) // while true
	{
		int input = 0; //important to zero any reusable variables
		float average = 0;
		printf("\nEnter temperature: ");
		scanf("%d", &input);
								//What follows is a "while loop" version of a standard "for loop"
		if (iteration % 2 == 0) temp2 = input;          //iteration starts at 1 and will therefore execute the "else" statement
		else if (iteration % 3 == 0) temp3 = input;	//iteration 2 and 3 will trigger the "if" statement and "else if" respectively 
		else temp1 = input;				
		average = (float)(temp1 + temp2 + temp3) / 3;	//Through every iteration, the input values are added to variable "average" and calculated
		if (average > 25) printf("\nAlarm!");
		iteration++;
	}
}
void labb6_b(void)
{
	int temperatures[] = { 0, 0, 0 }; // declaring and initializing an array with three, zeroed, elements
	for (int index = 0; index < 3; index++)
	{
		int sum = 0;
		float average = 0;
		printf("\nEnter temperature: ");
		scanf("%d", &temperatures[index]); //starting index = 0 means the first element in the temperatures array { 0, 0, 0 } takes first input
		//compute avrg for every iteration									    ^
		for (int index_avrg = 0; index_avrg < 3; index_avrg++)
		{
			sum += temperatures[index_avrg];
		}
		average = (float)(sum / 3);
		if (average > 25) printf("\nAlarm!");
		if (index == 2) index = -1; 
		/* 
		restarts the loop if the alarm was not raised.
		in the loop "for (int index = 0; index < 3; index++)" the last statement on the right allways goes last.
	        which means if we were to set index to 0 the following would occur: 
		1) index = 0;
		2) index++;  
		3) index = 1;
		4) inputs values into elements[1-3] instead of elements[0-2] 
		Setting index = -1 ticks it over to index = 0 before running the loop again
	}
}
