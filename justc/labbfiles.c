#include <stdio.h>
#include <time.h>
#include <string.h>

#define STRLEN 100

void labb1(void);
void AppendToLogFile(char* filename, char* text);
void get_date(char* time_string);


int main(void)
{
    labb1();
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
    // pointer of type file
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
void get_date(char* time_string)
{
    struct tm* units;
    time_t calendar = time(NULL);

    units = localtime(&calendar);

    // formats time string
    strftime(time_string, STRLEN, "%Y-%m-%d %X", units);
}