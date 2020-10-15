int strcmp(const char* p1, const char* p2)
{
	/*
		The arguments are just input strings with arbitrary names
		passed as chars because they're supposed to be strings
		and const to indicate that they will not be modified
		in the function(passed as pointers though!)
	*/
	const unsigned char* s1 = (unsigned char*)p1; // recasting p1 pointer type from char to
	const unsigned char* s2 = (unsigned char*)p2; // unsigned and keeping it as a pointer

	/*
		So first off, to understand why we're casting we have to
		get "bare metal"(my teacher looooved saying that) for a sec.

		the basic data types are stored as bytes that are made up
		off bits, 8 bits to be precise.
		so 00001010 are 8 bits that equal 10 in decimal this is
		how the memory cell for "int var = 10;" looks(not really)

		11111111 == 255 -- unsigned char
		01111111 == 127 -- regular old signed char

		unsigned char having a larger range than signed char
		due to not using a bit as a sign(+/-), removing the
		sign increases the range from 127 to 255

		using unsigned char(with a larger range) allows for
		representation of a larger conversion table like
		the extended ASCII table linked below.

		So I see the casting to unsigned char from char
		as a more of an in case or making the function
		safer.

		see
		standard ASCII table http://www.asciitable.com/
		compared to
		Extended ASCII table https://www.ascii-code.com/
		which uses the full range up to 255
	*/

	unsigned char c1, c2; // variables to hold elements
	do
	{
		c1 = (unsigned char)*s1++; // loops through s1, casts to unsigned char
		c2 = (unsigned char)*s2++;
		/*
			Here we do four things.

			1. use dereference marker "*" to access the value
			   /element of the string.
			2. recast the type of that element from char to
			   unsigned char.
			3. assigns the converted value to variables c1 and c2
			4. then we increment the pointer so that it points
			   to the next element in char array/string kinda
			   like how we increment index in a foor loop.		
		*/
		if (c1 == '\0') return c1 - c2;
		/*
			here we just check for an EOF which tells us that we've reached
			the end of the string and we can exit the function

			and when we do we return the numerical difference between the
			last characters in the string.
		*/
	} while (c1 == c2);

	/*
		The condition of the while loop in plain english means
		that keep going if the last two read characters match

		so strcmp() compares the last MATCHING characters of two
		strings and returns the numerical difference(int) giving
		rise to three different possibilites.

		c1 > c2 --> strcmp returns a positive value greater than zero
				

		c1 == c2 --> strings match and strcmp returns zero


		c1 < c2 --> strcmp returns a negative value less than zero

		the greater or less than zero values allow strcmp() to be used
		to sort strings in lexiographical order

		I mostly use it to match strings, never have I had to sort strings
		in this way.
	*/

	return c1 - c2; // this is in case the second string ends before the first one
}
/*
	- checks first not matching character
	- returns int value of it
*/
