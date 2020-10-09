/*
	#include är C:s motsats till import i Python där man gör ett bibliotek med funktioner(metoder?) tillgängliga för programmet.
	detta bibliotek (stdio.h) innehåller funktioner relaterad till input/output, så print funktioner, input funktioner och funktioner
	för att komma åt filer

	De bör placeras längst upp i filen då preprocessor/kompilator läser uppifrån och ned. Om du placerar en funktion från stdio.h innan du inkluderad
	den kommer kompilatorn inte fatta vad du menar för den har inte läst in det biblioteket än, dvs kompilatorn kommer få ett smärre sammanbrott.

*/
#include <stdio.h>

/*
	Här är nedanför våran main funktion, utgångspunkten för hela vårt program som du måste(så vitt jag vet iaf) inkludera så att datorn fattar vart
	den ska börja köra ifrån. Super duper duper viktigt, min bok har en stor varningstriangel bara för att man ska fatta hur viktig.

	C är en så kallad "static typed language" vilket betyder att du måste förklara typ allt för kompilatorn/preprocessorn ska förstå vad den håller på
	med. Har att göra med något skumt minnes hokus pokus som vi kommer komma in lite på senare(mallooooooc å bits å bytes)
	Iaf, rent praktiskt betyder att om du vill ha variabel med en int i så måste du skriva int innan.

	t.ex "int whateva = 0;"
	eller
	"float down_here = 0;"
	"char charizard = 'A';" - inga str typer dock

	På samma sätt behöver vi deklarera funktioner också, så datorn vet vad funktionen kommer returnera(annars härdsmälta).
	Alltså en funktion som returnerar summan av två ints kommer ha deklarationen int innan för att den returnerar en int.

	main funktionen är int för... standarder?
	main brukar returnera 0 så man vet att programmet inte kraschat eller gjort något skumt, vissa kompilatorer brukar klaga
	om du inte returnerar 0. GCC(min... våran kompilator?) brukar inte bry sig om du utelämnar "return 0;"

	Okej sista innan vi hoppar in i funktionen!
	"void" betyder bara att vi inte stoppar in nånting som funktionsargument, nada! du skulle tillochmed kunna skippa att
	skriva void där om du ville, men det brukar vara bra praxis att skriva void om du saknar funktionsargument

*/

int main(void)
{
	/*
		Det här är c motsvarighet till Pythons print som skriver ut våran sträng
		"Hello World" och "\n" som är en "new-line character" dvs den säger åt
		våran printf funktionen att skapa en ny rad(du kan sätta en ny rad vart du vill
		i strängen)

		Och det suuuuper viktiga i C så avslutar du med ett litet semi-colon ";" så att
		kompilatorn/preprocessorn fattar att du vill exekvera(köra) det kommandot
		skriv ; efter allt, alltså allt allt;
	*/
	printf("Hello World!\n");
} //  <-- jag glömde nästan de här, de definerar kodblock, allt du indenterar på i python, sätter du sånna här på i C(wiktigt)

/*
								KÖRA PROGRAMMET

	I Visual Studio borde det räcka med att installerat C++ developer suite(vad det nu än hette), du kan köra set-up igen om du glömde.
	Därefter bara debugga, jag hade lite problem med det först,(Anti-Virus trodde min .exe var virus) och du kan behöva byta från
	"x86" till "x64" men det kan vara för att jag har GCC installerat(local windows debugger står det för mig)

	Debugg och kör helt enkelt.


	LITE MER MANUELLT -

	Du kan alltid ladda ner GCC https://osdn.net/projects/mingw/releases/
	och själv bygga dina filer från en terminal(typ Powershell eller liknande).
	Det är inte svårt jag lovar och man känner sig lite mer haxxor när man skriver från terminal

	När den är installerad så är det bara att navigera till den folder där du har din source fil(intro.c)
	skriva "gcc intro.c -o intro.exe" sen har du en exekverbar fil som du kan köra
	(I windows) ".\intro.exe" för att köra

	På så sätt kan du skriva koden i vilken editor du vill och kompilera och köra den själv.
	Seriöst, du kan skriva din kod i .txt fil om du vill och kompilera
*/
