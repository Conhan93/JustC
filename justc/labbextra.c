#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void labb2a();
void labb2b();

void print_array(int* array, size_t size);
void read_ints(int* array, size_t* size);
void print_sum(int* array, size_t size);

void labb3();
void labb4();
void labb5();
void labb6();

void labb7();
void remove_not_letter(char* orig, char* new);

int main()
{
    //labb2a();
    //labb2b();

    //labb3();
    //labb4();
    //labb5();
    //labb6();
    labb7();
}
void labb2a()
{
    /*
        Enter any number of values on one line, seperated by a space
        ex: 12 99 24 11 34

        Read and store the values in an array and the print them.
    */
    // declare int array and size
    int* array = malloc(sizeof(int));
    size_t size = 0;

    // fill array
    read_ints(array, &size);
    // print array
    print_array(array, size);

    // free malloc:ed array space
    free(array);
}
void labb2b()
{
    /*
        Enter any number of values on one line, separated by spaces.

        Save values in an array then call a separate function to
        calculate and print their sum.
    */
    // declare int array and size
    int* arr = malloc(sizeof(int));
    size_t arr_size = 0;

    // fill array
    read_ints(arr, &arr_size);
    // print sum of array
    print_sum(arr, arr_size);

    // free malloc:ed array space
    free(arr);
}
void print_sum(int* array, size_t size)
{
    // stores sum
    int sum = 0;
    // loop through array, add values onto sum
    for (int index = 0; index < size; index++)
        sum += array[index];
    // print sum
    printf("\nSum: %d", sum);
}
void print_array(int* array, size_t size)
{
    // text
    printf("\nSCANNED:\n");
    // loop through array, printing member integers
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}
void read_ints(int* array, size_t* size)
{
    // prompt
    printf("\nENTER NUMBERS: ");
    // stores chars in between numbers
    char read_char = 0;


    int index = 0;
    // for loop until it encounters newline char
    for (int read_int = 0; read_char != '\n'; index++)
    {
        // get int and char from stdin
        scanf("%d%c", &read_int, &read_char);
        {
            // grow array
            if (index > 0) array = realloc(array, (sizeof(int) * (index + 1)));
            // put read int into array
            array[index] = read_int;

        }
    }
    // save size
    *size = index;
}
void labb3()
{
    /*
        Enter a string
        Parse the string and check if all the character are the same.
        if not: print "No"
        if true: print "Yes"
    */
    char string[100];

    printf("\nEnter string: ");
    scanf("%s", string);

    // get first character in string
    char first_letter = string[0];

    // loop through string until it encounters end of line character
    for (int index = 0; string[index] != '\0'; index++)
        // compare each character to the first one
        if (string[index] != first_letter)
        {
            // if they don't match
            printf("\nNo");
            return;
        }
    printf("\nYes");
}
void labb4()
{
    /*
        Enter a string, parse it and find the most occuring
        character.(most common char in string)
    */
    char string[100];

    // awful variable names
    char common_letter = 0;
    int count = 0;

    // prompt
    printf("\nEnter string: ");
    // scan till newline, leave it on stdin then scan newline and supress it
    scanf("%[^\n]%*c", string);

    for(int letter = 0 ; string[letter] != '\0' ; letter++)
    {
      int current_letter_count = 0;
      for(int index = 0 ; string[index] != '\0' ; index++)
      {
          if(string[letter] == string[index]) current_letter_count++;
      }
      if(current_letter_count > count)
      {
        count = current_letter_count;
        common_letter = string[letter];
      }
    }

    printf("\nThe most common letter is %c, found %d times.",
            common_letter, count);
}
void labb5()
{
    /*
        Enter a string, enter a start position and an
        end position and get the substring between
        those two positions
    */
    char string[100];
    int start = 0, end = 0;

    // get string
    printf("\nEnter string: ");
    scanf("%[^\n]%*c", string);

    // get positions
    printf("\nEnter starting pos: ");
    scanf("%d%*c",&start);
    printf("\nEnter end pos: ");
    scanf("%d%*c",&end);

    // print substring
    printf("\nSubstring between %d and %d is: ", start, end);
    for(int pos = start ; pos != end ; pos++) printf("%c",string[pos]);
}
void labb6()
{
  /*
      Enter a string and change the case on every char
  */
  char string[100];

  // get string
  printf("\nEnter string: ");
  scanf("%[^\n]%*c", string);

  // loop through string, use is(upper/lower) to check char
  // use to(upper/lower) to change them
  for(int index = 0 ; string[index] != '\0'; index++)
    if(isupper(string[index])) string[index] = tolower(string[index]);
    else if(islower(string[index])) string[index] = toupper(string[index]);

  printf("\nString : %s", string);

}
void labb7()
{
  /*
      Enter a string and remove anything that's not
      a letter.
  */
  char string[100], new_string[100];

  // get string
  printf("\nEnter string: ");
  scanf("%[^\n]%*c", string);

  remove_not_letter(string, new_string);

  printf("\nFiltered: %s",new_string);


}
void remove_not_letter(char* orig, char* new)
{
  // while orig
  while(*orig != '\0')
  {
    // if *orig is a letter
    if(isalpha(*orig))
    {
      // add letter to new and increment new pos
      *new = *orig;
      new++;
    }
    // next char in orig
    orig++;
  }
  // add end of line char to close new
  *new = *orig;
}
