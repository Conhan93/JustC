#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define STRLEN 100

void labb1(void);
void AppendToLogFile(char* filename, char* text);
void get_date(char* time_string);
void labb2(void);
void labb2function1(void);
void labb2function2(void);
void labb3(void);
int labb3function(char* filename);

int main(void)
{
    //labb1();
    //labb2();
    labb3();
}
void labb1(void)
{
    char filename[STRLEN], text[STRLEN];

    printf("\nEnter filename: ");
    scanf("%s", filename);
    printf("\nEnter text: ");
    scanf(" %[^\n]%*c", text);

    AppendToLogFile(filename, text);

}
void AppendToLogFile(char* filename, char* text)
{
    // pointer of type FILE
    FILE* f_ptr;

    // assign pointer to file/stream in append mode
    f_ptr = fopen(filename, "a");

    if (f_ptr != NULL)
    {
        char time_string[STRLEN];
        get_date(time_string);
        fprintf(f_ptr, "%s\t%s\n", time_string, text);
        /*
            fprintf works just like printf but instead of terminal
            it prints to file instead, also it needs a FILE pointer
            argument to let it know which file to print to.
        */

    }
    fclose(f_ptr); // closes file, very important!
}
void labb2(void)
/*
        a.) Write a function that counts the number of lines in a file
        b.) Write a function that counts the number of words(split at ' ', '.', '?', ';', ':')
*/
{
    //labb2function1();
    labb2function2();
}
void labb2function1(void)
{
    char filename[] = "text2.txt", buffer[STRLEN];
    int line_count = 0;

    FILE* file;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("\nNo file found");
        return;
    }
    while (fgets(buffer, STRLEN, file)) line_count++;
    /*
        fgets reads one line at a time so we increment
        the number of lines read everytime the function runs.
    */

    printf("\nnr_lines: %d", line_count);
}
void labb2function2(void)
{
    char filename[] = "text2.txt"; // the name of the file you want to open
    char charizard;
    int word_count = 0;

    // file pointer, points to a file
    FILE* file;

    // assign file pointer to file
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("\nNo file found");
        return;
    }
    while ((charizard = fgetc(file)) != EOF)
        if (!isalnum(charizard)) word_count++;
    /*
        fgetc() reads one character at a time from the file
        then we assign it to charizard and the same time
        check that we haven't reached the end of the file"!= EOF"

        "!isalnum" checks if the character read is not alphanumeric.
        if it is not then we increase our word count.
    */

    fclose(file); // closes file, very important!

    printf("\nnr of words: %d", word_count);
}
void labb3(void)
/*
    Write a function that deletes a file if it exists
        returns 1 if file existed
        returns 0 if not
*/
{
    char filename[] = "text1.txt";
    if (labb3function(filename)) printf("\nfile removed");
    else printf("\nno file found");
}
int labb3function(char* filename)
{
    // remove deletes file, returns 0 if succesfull otherwise 1
    if (!remove(filename)) return 1;
    else return 0;
}
void get_date(char* time_string)
{
    /*
        Returns a formatted string with y-m-d and time
    */
    struct tm* units;
    time_t calendar = time(NULL);

    units = localtime(&calendar);

    strftime(time_string, STRLEN, "%Y-%m-%d %X", units);
}