#include <stdio.h>
#include <string.h> // contains functions related to strings
#include <stdlib.h> // contains a lot of utilitarian functions( atoi() )
#include <ctype.h> // included for the function: tolower()


#define STRLEN 100 // Macro used for max length of strings

// functions prototypes
void labb1(void);
void labb2(void);
void labb3(void);
void labb4(void);
void labb5(void);
void labb6(void);
void labb7(void);
void labb8(void);
void labb9(void);
void labb10(void);




void main(void)
{ // main function sequence
	labb1();
	labb2();
	labb3();
	labb4();
	labb5();
	labb6();
	labb7();
	labb8();
	labb9();
	labb10();
}
void labb1(void)
/*
	Ask the user to enter a number
		Check if the number is greater than 10.
		Notify the user if the number is greater than 10 - "Number is greater than 10." <-- print that
		If less than print --> "Number is less than 10"
*/
{
	int tal = 0, kontroll = 10;

	printf("Enter number: ");
	scanf("%d", &tal);
	if (tal > kontroll)
	{
		printf("\nNumber is greater than 10.");
	}
	else if (tal < kontroll)
	{
		printf("\nNumber is less than 10.");
	}
}
void labb2(void)
/*
	Ask the user the enter the number of milk cartons left-
		If less than 10 print - Order 30 packets.
		If between 10 and 20 print - order 20 packets.
		Else print - You do not need to order milk.
*/
{
	int nr_milk_cartons = 0;
	printf("\nAmount of milk cartons/packets left: ");
	scanf("%d", &nr_milk_cartons);
	if (nr_milk_cartons < 10)
	{
		printf("\nOrder 30 packets.");
	}
	else if (nr_milk_cartons >= 10 && nr_milk_cartons <= 20) // Boolian expression && == "and" keyword in Python.
	{
		printf("\nOrder 20 packets/cartons dude.");
	}
	else printf("\nDon't need no milk.");
}
void labb3(void)
/*
	Ask the user for temperature input from a body temp gauge
		If temp is over 37.8 write - you have a fever.
		If greater than 39.5 write - You should see a doctor.
		If less than 37.8 write - You don't have a fever.
*/
{
	float temperature = 0;
	printf("\nEnter temperature: ");
	scanf("%d", &temperature);
	if (temperature > 39.5) printf("\nYou should see a doctor.."); // pay attention the order of condition checks on this labb
	else if (temperature > 37.8) printf("\nyou have a fever.");
	else printf("\nYou don't have a fever.");
	
	//Ask yourself what would happen if you reverse the order of the conditionals above
}
void labb4(void)
/*
	Ask the user to enter their age.
		If less than 18 then user is not "of age". If over 65 then user is a retiree.
		Otherwise user is of age but not retiree. Notify user of their "status"
		Check if user input is an actual number(check if int)
		If invalid input print out "Wrong age"
*/
{
	char input[STRLEN];
	int age = 1;
	printf("\nenter age: ");
	scanf("%s", input);

	if (age = atoi(input))
		/* Technically, this is an extra feature outside of stated lab parameters but is still nice to have
		*  atoi() returns value of input if it is able to, otherwise it returns 0
		*  In C 0 == False when evaluated as a boolean expression/condition check
		*  So this if-statement checks if input is able to be converted to int(if int == valid input)
		*/
	{
		if (age < 18) printf("\nnot of age");
		else if (age >= 18 && age <= 65) printf("\nof age but not too old");
		else if (age < 65) printf("\nGeezer!");
		else printf("\nWrong Age");
	}
	else printf("\nInvalid Input");
}
void labb5(void)
/*
	Let the user enter a category(Adult, Student, Retiree)
		If retiree or Student, trip costs 20 kr
		If Adult, trip costs 30 kr
		Otherwise let the user know they entered an invalid category

	Does Stefan want us to use strings for these?(string operations further down)
*/
{
	int category = 0;
	printf("\nEnter category(1, adult, 2 student, 3 retiree): ");
	scanf("%d", &category);
	if (category == 2 || category == 3) printf("\nTrip costs 20 kr"); // dubbla strecken || == "or" i python.
	else if (category == 1) printf("\nTrip costs 30 kr");
	else printf("\nInvalid Input");
}
void labb6(void)
/*
	Let the user enter their year of birth.
		If greater or equal to 1980 but less than 1990 - print "born in the 1980's"
		If less than 2000 but greater than or equal to 1990 - print "born in the 90's"
		If less than 1980 or greater than or equal to 2000 - print "not born in 80's or 90's"
		
*/
{
	int birth_date = 0;
	printf("\nEnter year of birth: ");
	scanf("%d", &birth_date);
	if (birth_date >= 1980 && birth_date < 1990) printf("\nborn in the 1980's");
	else if (birth_date >= 1990 && birth_date < 2000) printf("\nborn in the 90's - best decade");
	else printf("\nnot born in 80's or 90's");
}
void labb7(void)
/*
	Create a log in where user must enter username and then password
		Create constants for username and password.
		Check if input matches with username and password
		Notify user of log-in or if password or username is invalid
*/
{
	char username[] = "admin", password[] = "password";
	char input_username[STRLEN], input_password[STRLEN];
	printf("\nEnter username: ");
	scanf("%s", input_username);
	printf("Enter password: ");
	scanf("%s", input_password);
	if (!strcmp(username, input_username) && !strcmp(password, input_password)) printf("\nLogged in");
	// strcmp() from <string.h> compares strings and returns 0 if they match. Exclamation mark is equal to "not" in Python(Also known as "negation")
	// so !strcmp(username, input_username) evaluates to "True" if the strings match, It's a bit of a double negative, strcmp == 0 which is false,
	// but negated to True through "not" or use of "!".
	// So in practice !strcmp(string1, string2) evaluates to True if strings match
	else
	{
		if (strcmp(username, input_username)) printf("\nWrong Username"); // Here we check if strcmp returns !0(not 0) which means the strings
		if (strcmp(password, input_password)) printf("\nWrong Password"); //     don't match! 
	}
}
void labb8(void)
/*
	Ask the user to enter the name of the country they're frp,
		IF they're from sweden, denmark or norway, inform them they're from scandinavia
		If not, let them know they're not from scandinavia
*/
{
	char scandinavian_countries[] = "swedendenmarknorway";
	char your_country[STRLEN];
	printf("\nEnter your country of origin: ");
	scanf("%s", your_country);
	for (int index = 0; index < strlen(your_country); index++)
		your_country[index] = tolower(your_country[index]);
	/*
		Alright here's a small for loop where we loop through the elements of the your_country string
		and using the tolower() function to change the elements to lowercase(this is so the search is not case sensitive)
		tolower() is a function that takes a char argument and returns it but in lowercase()
	*/
	if (strstr(scandinavian_countries, your_country)) printf("\nyou live in scandinavia!");
	/*
		strstr() is a function that searches for a substring(your_country) in a main string(scandinavian_countries) and returns
		a pointer to the substrings first occurence(something), if none is found it returns NULL.
		in this example it's just used a boolean type check to see if it finds the substring at all.
		then the pointer will be evaluated as True
	*/
	else printf("\nYou don't live in scandinavia!");
}
void labb9(void)
/*
	Ask the user to enter a car brand
	If it's not equal to Volvo you'll check if it's a Volkswagen, BMW or Audi, then print out "german car"
	If Renault, Peugeot or Citroen print - "french car"
	Otherwise print out, "not german or french"
	print nothing if car brand is volvo
*/
{
	char car_brand[STRLEN];

	printf("\nenter car brand: ");
	scanf("%s", car_brand);
	for (int index = 0; index < strlen(car_brand); index++)
		car_brand[index] = tolower(car_brand[index]);
	
	if (strcmp(car_brand, "volvo")) //This returns 0 if it matches with volvo (see labb7). (if input == volvo -> ignore everything under this if-statement)
	{
		if (strstr("volkswagenbmwaudi", car_brand)) printf("\ngerman car");
		else if (strstr("renaultpeugeotcitroen", car_brand)) printf("\nfrench car");
		else printf("\nnot german or french");
	}
}
void labb10(void)
/*	Ask the user to enter an amount of money.
		Then ask the user if they have access to a discount
		a. If amount is between 15 and 25 and user does not have a discount print - "small hamburger"
		b. If amount is between 15 and 25 but user has discount print  – "small hamburger and small fries"
		c. If amount is greater than 25 and smaller or equal to 50 but no discount print - "big burger"
		d. If amount is greather than 25 and smaller or equal to 50 but has discount print  – "big burger and fries"
		e. If amount is greater than 60 or equal to 50 or 60 and has user has discount print -  "meal and drink"
*/
{
	int summa = 0;
	char rabatt = 'n';
	printf("Enter amount of money: ");
	scanf("%d%*c", &summa); // The extra (%*c) tells your scan to not save the newline input (pressing enter)
				// Without it, the next scanf(line 249) will take this previous newline and input it into "rabatt"
				// This will ofcourse not meet any conditionals and subsequently end the program

	printf("do you have a discount?(y/n): ");
	scanf("%c", &rabatt);
	if (summa >= 15 && summa <= 25)
	{
		if (rabatt == 'y') printf("\nsmall hamburger and small fries");
		else printf("\nsmall hamburger");
	}
	else if (summa > 25 && summa <= 50)
	{
		if (rabatt == 'y') printf("\nbig burger and fries");
		else printf("\nbig burger");
	}
	else if ((summa > 60 || summa == 50 || summa == 60) && rabatt == 'y') printf("\nmeal and drink"); // parenteser mannen!

}
