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
    FILE* f_ptr;

    f_ptr = fopen(filename, "a");

    if (f_ptr != NULL)
    {
        char time_string[STRLEN];
        get_date(time_string);
        fprintf(f_ptr, "%s\t%s\n", time_string, text);

    }
    fclose(f_ptr);
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

    printf("\nnr_lines: %d", line_count);
}
void labb2function2(void)
{
    char filename[] = "text2.txt";
    char charizard;
    int word_count = 0;

    FILE* file;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("\nNo file found");
        return;
    }
    while ((charizard = fgetc(file)) != EOF)
        if (!isalnum(charizard)) word_count++;

    fclose(file);

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
    struct tm* units;
    time_t calendar = time(NULL);

    units = localtime(&calendar);

    strftime(time_string, STRLEN, "%Y-%m-%d %X", units);
}