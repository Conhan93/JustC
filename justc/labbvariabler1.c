#include <stdio.h>
#include <stdlib.h>
/*
	<stdlib> = standard library
	använder för att få tillgång tills abs(x) som returner det absoluta värdet av x som en int 
*/

#define STRLEN 100
/*
	definerar en global konstant STRLEN = 100 som ska vara våran max längd/storlek för de strängar
	vi använder

	Konstanter brukar skrivas med bara STORA BOKSTÄVER
*/



void labb1(void);
void labb2(void);
void labb3(void);
void labb4(void);
void labb5(void);
void labb6(void);
void labb7(void);
void labb8(void);
void newlabb(void); // skapar bara lite nya rader mellan labbarna




int main(void)
{
	labb1();
	labb2();
	labb3();
	labb4();
	labb5();
	labb6();
	labb7();
	labb8();
}

void labb1(void) // Skriv ut Hello + ditt namn i Console applikationen på skärmen
{
	newlabb();
	char namn[STRLEN] = "skriv in ditt namn har";

	printf("Hello %s", namn);

}

void labb2(void)
/*
	Skapa en Application.
		a. Skapa en variabel string name med ditt namn
		b. Skapa en int age med din ålder.
		c. Skriv sedan ut Jag heter Kalle (innehållet i name) och är 27(innehållet i age) år.
*/
{
	newlabb();
	char namn[STRLEN] = "skriv in ditt namn har";
	int age = 0; // skriv in din ålder här

	printf("Jag heter %s och ar %d ar gammal", namn, age);
}

void labb3(void)
/*
	Skapa en applikation där användaren matar in för och efternamn.
		a. Skriv ut Skriv in ditt förnamn: . Ta emot värdet i en variabel
		b. Låt markören vänta på din inmatning på samma rad.
		c. Gör på samma sätt med efternamnet.
		d. Skriv sedan ut namnen i omvänd ordning.
		e. Se till att resultatet ser ut så här.(stefans bild!)
*/
{
	newlabb();
	char fornamn[STRLEN], efternamn[STRLEN];
	printf("skriv in ditt fornamn: ");
	scanf("%s", fornamn);
	printf("\nskriv in ditt efternamn: ");
	scanf("%s", efternamn);
	printf("\nDu heter %s, %s", efternamn, fornamn);

}
void labb4(void)
/*
	Skapa en applikation där användaren matar in två tal
		a. Skriv in Mata in tal 1:
		b. Ta emot detta tal i en variabel
		c. Skriv in Mata in tal 2:
		d. Ta emot värdet på detta tal
		e. Skriv ut på skärmen - Summan av tal1 och tal 2 är: summan
*/
{
	newlabb();
	int tal1 = 0, tal2 = 0;

	printf("Mata in tal 1: ");
	scanf("%d", &tal1);
	printf("\nMata in tal 2: ");
	scanf("%d", &tal2);
	printf("\nSumman av tal1 och tal2 är: %d", tal1 + tal2);
}

void labb5(void)
/*
	Skriv ett program som tar in ett födelse år från användaren.
		a. Ta emot födelseåret och räkna ut personens ålder
		b. Skriv på skärmen- Din ålder är : ålder
		c. Pröva att sätta dagens datum i en variabel och utgå från årtalet i detta datum i din beräkning.
*/
{
	newlabb();
	int date_of_birth = 0, current_year = 2020;
	printf("Skriv in fodelsear: ");
	scanf("%d", &date_of_birth);
	printf("\nDu ar %d ar gammal", current_year - date_of_birth);
}

void labb6(void)
/*
	Mata in två tal och returnera medelvärde, summa och differens mellan dessa tal
		a.Skriv in Mata in tal 1:. Ta emot i en variabel
		b.Skriv Mata in tal 2: . Ta emot i en variabel
		c.Räkna ut medelvärde, summa och differens mellan dessa två tal
		d. Skriv ut de beräknade värdena på skärmen
*/
{
	newlabb();
	int tal1, tal2;
	printf("Mata in tal1: ");
	scanf("%d", &tal1);
	printf("\nMata in tal2: ");
	scanf("%d", &tal2);
	printf("\nMedelvarde: %.2f\nSumma: %d\nDifferens: %d", (float)(tal1 + tal2) / 2, tal1 + tal2, abs(tal1 - tal2));
}
void labb7(void)
/*
	Be användaren mata in en summa.
		Lägg på 25% moms dvs summan gånger 0,25 och skriv på skärmen den nya summan med moms
*/
{
	newlabb();
	int summa = 0;
	printf("Mata in din summa: ");
	scanf("%d", &summa);
	printf("Med moms: %.2f", summa * 1.25);
}
void labb8(void)
/*
	Skapa ett program där användaren matar in ett antal minuter(minst 60 minuter). Programmet omvandlar sedan detta till timmar och minuter.
		a. Skriv in ”Mata in antal minuter:”
		b. Ta emot detta tal
		c. Räkna om detta till antal timmar och minuter
		d. Skriv ut på skärmen- Detta är .. timmar och … minuter
*/
{
	newlabb();
	int minutes = 0, hours = 0;
	do
	{
		printf("Mata in antal minuter: ");
		scanf("%d", &minutes);
	} while (minutes < 60);
	hours = (int)minutes / 60;
	minutes = minutes % 60;
	printf("Detta ar %d timmar och %d minuter", hours, minutes);
}
void newlabb(void)
{
	printf("\n\n");
}