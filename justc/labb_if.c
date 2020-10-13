#include <stdio.h>
#include <string.h> // funktioner relaterande till strängar
#include <stdlib.h> // innehåller en massa kul grejer( atoi() )
#include <ctype.h> // inkluderad för tolower()


#define STRLEN 100


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
{
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
	Be användaren att mata in ett tal.
		Kontrollera om talet är större än 10.
		Meddela användaren om talet är större än 10- Talet är större än 10.
		Om det är mindre än 10 meddela användaren – Talet är mindre än 10
*/
{
	int tal = 0, kontroll = 10;

	printf("Mata in tal: ");
	scanf("%d", &tal);
	if (tal > kontroll)
	{
		printf("\nTalet ar storre an 10.");
	}
	else if (tal < kontroll)
	{
		printf("\nTalet ar mindre an 10.");
	}
}
void labb2(void)
/*
	Be användaren att mata in hur många paket mjölk som finns kvar.
		Är det mindre än 10 skriv- Beställ 30 paket.
		Är det mellan 10 och 20 skriv- Beställ 20 paket.
		Annars skriv-Du behöver inte beställa någon mjölk.
*/
{
	int nr_milk_cartons = 0;
	printf("\nHur manga mjolk paket finns kvar?: ");
	scanf("%d", &nr_milk_cartons);
	if (nr_milk_cartons < 10)
	{
		printf("\nBestall 30 paket.");
	}
	else if (nr_milk_cartons >= 10 && nr_milk_cartons <= 20) // booleskt uttryck && == "and" i python
	{
		printf("\nBestall 20 paket mannen.");
	}
	else printf("\nBehover ingen mjolk.");
}
void labb3(void)
/*
	Be användaren mata in temperaturen tagen från en febertermometer.
		Om tempen är över 37.8 skriv- Du har feber.
		Om den är över 39.5 skriv-Du bör uppsöka läkare.
		Om den är mindre än 37.8 skriv- Du har inte feber.
*/
{
	float temperature = 0;
	printf("\nMata in temperatur: ");
	scanf("%d", &temperature);
	if (temperature > 39.5) printf("\nDu bor uppsoka lakare.");
	else if (temperature > 37.8) printf("\nDu har feber");
	else printf("\nDu har inte feber.");
}
void labb4(void)
/*
	Be användaren mata in sin ålder.
		Om den är mindre än 18 är användaren ej myndig. Om den är över 65 är den pensionär.
		Annars är den myndig men inte pensionär. Meddela användaren om vad som gäller beroende på dennes ålder.
		Kontrollera också att användaren har matat in ett riktigt tal.
		Har den matat in andra tecken än siffror meddela användaren att den har ar matat in en felaktig ålder.
*/
{
	char input[STRLEN];
	int age = 1;
	printf("\nAnge alder: ");
	scanf("%s", input);

	if (age = atoi(input))
		/* atoi() returnerar int värdet av input om det går annars returnerar den 0
		*  I C så är 0 == False när den utvärderas som ett booleskt uttryck
		*  så den här if satsen kollar om det går att konvertera input till en integer
		*/
	{
		if (age < 18) printf("\nEj myndig");
		else if (age >= 18 && age <= 65) printf("\nMyndig, ej pensionar");
		else if (age < 65) printf("\nPensionar!");
		else printf("\nFelaktig alder");
	}
	else printf("\nFelaktig inmatning");
}
void labb5(void)
/*
	Be användaren ange vilken kategori den tillhör-vuxen, pensionär, student.
		Om den är pensionär eller student kostar resan 20 kr.
		Om den är vuxen kostar resan 30 kr.
		Annars skall användaren informeras att den har angett en felaktig kategori.

	Vill stefan att man ska använda strängar här? kommer ju senare
*/
{
	int category = 0;
	printf("\nAnge kategori(1, vuxen, 2 student, 3 pensionar): ");
	scanf("%d", &category);
	if (category == 2 || category == 3) printf("\nResan kostar 20 kr"); // dubbla strecken || == "or" i python.
	else if (category == 1) printf("\nResan kostar 30 kr");
	else printf("\nFelaktig inmatning");
}
void labb6(void)
/*
	Be användaren mata in sitt födelse år.
		Om det är större eller lika med 1980 men mindre än 1990 skriv ut –Du är född på 1980-talet.
		Om det är mindre än 2000 men större än eller lika med 1990 skriv ut- Du är född på 1990-talet.
		Om det är mindre än 1980 eller större än eller lika med 2000, skriv- Du är inte född på 1990 eller 1980-talen.
*/
{
	int birth_date = 0;
	printf("\nAnge fodelsear: ");
	scanf("%d", &birth_date);
	if (birth_date >= 1980 && birth_date < 1990) printf("\nFodd pa 80-talet");
	else if (birth_date >= 1990 && birth_date < 2000) printf("\nFodd pa 90-talet-basta talet");
	else printf("\nInte fodd pa 90 eller 80 -talen");
}
void labb7(void)
/*
	Skapa en inloggning där användaren först får ange användarnamn och sedan lösenord.
		Ange det som du anser vara riktiga uppgifter i två konstanter i koden.
		Kontrollera sedan om det är riktigt inmatat och meddela användare om
		den antingen är inloggad eller matat in fel lösenord eller fel användarnamn
*/
{
	char username[] = "admin", password[] = "password";
	char input_username[STRLEN], input_password[STRLEN];
	printf("\nMata in anvandarnamn: ");
	scanf("%s", input_username);
	printf("Mata in losenord: ");
	scanf("%s", input_password);
	if (!strcmp(username, input_username) && !strcmp(password, input_password)) printf("\ninloggad");
	// strcmp() från <string.h> jämför strängar, returnerar 0 om de är lika. uttropstecknet i C är lika med "not" i python
	// så !strcmp(username, input_username) ger True ifall strängarna matchar, det är lite dubbel negativ.
	// strcmp ger 0 som är lika med False om strängarna matchar, men med vårat "!" så letar vi efter False som då blir utvärderad som True
	// för vi hittade vad vi letade efter! kanske är lite rörigt.
	else
	{
		if (strcmp(username, input_username)) printf("\nFel anvandarnamn"); // här kollar vi om strcmp() inte ger 0, dvs strängarna matchar inte!
		if (strcmp(password, input_password)) printf("\nFel losenord");
	}
}
void labb8(void)
/*
	Be användaren att mata in namnet på ett land där den bor.
		Om det är Sverige, Danmark, eller Norge skall användare informeras att-Du bor i Skandinavien.
		Om inte meddela användaren att den inte bor i Skandinavien.
*/
{
	char scandinavian_countries[] = "sverigedanmarknorge";
	char your_country[STRLEN];
	printf("\nMata in ditt land: ");
	scanf("%s", your_country);
	for (int index = 0; index < strlen(your_country); index++)
		your_country[index] = tolower(your_country[index]);
	/*
		Okej först har vi en loop som går igenom strängen där vi tryckte in vår input
		sen på varje plats i den här strängen ersätter vi char:en med en lowercase av den char:en
		genom funktionen tolower() som tar en char som argument och returnerar en lowercase version
		av den char:en
	*/
	if (strstr(scandinavian_countries, your_country)) printf("\nDu bor i skandinavien");
	/*
		strstr() letar efter substrängen(your_country) i huvudsträngen(scandinavian_countries) och returnerar en pekare(nånting)
		till den första platsen den hittar den och NULL om inte. Rent praktiskt om du använder den i if sats så betyder den utvärderas
		till True ifall den hittar substrängen. då i C så är typ allt == True
	*/
	else printf("\nDu bor inte i skandinavien");
}
void labb9(void)
/*
	Be användaren mata in ett bilmärke.
	Om det inte är lika med Volvo skall du kontrollera om det är en Volkswagen, BMW eller Audi. Skriv ut att bilen är tysk.
	Om den är Renault eller Peugeot eller Citroen skriv att den är fransk.
	Annars skriv ut att bilen inte är tysk eller fransk eller svensk.
	Skriv inget om bilen är en Volvo.
*/
{
	char car_brand[STRLEN];

	printf("\nMata in bilmarke: ");
	scanf("%s", car_brand);
	for (int index = 0; index < strlen(car_brand); index++)
		car_brand[index] = tolower(car_brand[index]);
	if (strcmp(car_brand, "volvo"))
	{
		if (strstr("volkswagenbmwaudi", car_brand)) printf("\nBilen ar tysk");
		else if (strstr("renaultpeugeotcitroen", car_brand)) printf("\nBilen ar fransk");
		else printf("\nEj fransk eller tysk");
	}
}
void labb10(void)
/*	Be användaren mata in en summa på hur mycket pengar den har.
		Be sedan användaren att ange om den har rabatt.
		a. Om summan är mellan 15 och 25 och användaren inte har rabatt skriv – Du kan köpa en liten hamburgare. b
		. Om summan är mellan 15 och 25 och användaren har rabatt skriv – Du kan köpa en liten hamburgare och en pommes frites.
		c. Om summan är större än 25 och mindre än eller lika med 50 och användaren inte har rabatt skriv – Du kan köpa en stor hamburgare.
		d. Om summan är större än 25 och mindre än eller lika med 50 och användaren har rabatt skriv – Du kan köpa en stor hamburgare och pommes frites.
		e. Om summan är större än 60 eller om den är 50 och 60 och användaren har rabatt skriv – Du kan köpa ett meal med dryck.
*/
{
	int summa = 0;
	char rabatt = 'n';
	printf("Skriv in hur mycket du har: ");
	scanf("%d%*c", &summa);
	printf("Har du rabatt?(j/n): ");
	scanf("%c", &rabatt);
	if (summa >= 15 && summa <= 25)
	{
		if (rabatt == 'j') printf("\nLiten Hamburgare & Pommes");
		else printf("\nLiten Hamburgare");
	}
	else if (summa > 25 && summa <= 50)
	{
		if (rabatt = 'j') printf("\nStor hamburgare & pommes");
		else printf("\nStor hamburgare");
	}
	else if ((summa > 60 || summa == 50 || summa == 60) && rabatt == 'j') printf("\nMeal med dryck"); // parenteser mannen!

}