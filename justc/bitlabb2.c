#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BIT_SET(a, b) ((a) |= (1UL << b))
#define BIT_CHECK(a, b) ((a) & (1UL << b))

enum
{
    INCLUDE_DATE,
    INCLUDE_TIME,
    INCLUDE_DAY,
    UPPERCASE,
    TO_CONSOLE,
    TO_FILE
} WRITE_LOG_SETTINGS;


void AddWithSpaceIfNotEmpty(char* chBuf, char* chWhat, size_t size);
void WriteLogMessage(char* message, unsigned char settings);


int main()
{
    char message[512];
    unsigned char settings = 0;

    while (true)
    {
        printf("\nEnter message: ");
        scanf(" %[^\n]%*c", message);
        while (true)
        {
            int sel = 0;
            printf("\nChoose message settings."
                "\n1. include date."
                "\n2. include time."
                "\n3. include day of the week."
                "\n4. convert to uppercase."
                "\n5. print to console."
                "\n6. write to file."
                "\n7. execute\n");
            scanf(" %d%*c", &sel);
            switch (sel)
            {
            case 1:
                BIT_SET(settings, INCLUDE_DATE);
                break;
            case 2:
                BIT_SET(settings, INCLUDE_TIME);
                break;
            case 3:
                BIT_SET(settings, INCLUDE_DAY);
                break;
            case 4:
                BIT_SET(settings, UPPERCASE);
                break;
            case 5:
                BIT_SET(settings, TO_CONSOLE);
                break;
            case 6:
                BIT_SET(settings, TO_FILE);
                break;
            case 7:
                WriteLogMessage(message, settings);
                return 0;
            default:
                printf("\ninvalid input.");
                break;
            }
        }
    }
}
void WriteLogMessage(char* message, unsigned char settings)
{
    time_t seconds_since_1970 = time(NULL);
    struct tm* now = localtime(&seconds_since_1970);

    char buf[512];
    buf[0] = 0;

    if (BIT_CHECK(settings, INCLUDE_DATE))
    {
        char date[12];
        strftime(date, sizeof(date), "%Y-%m-%d", now);
        AddWithSpaceIfNotEmpty(buf, date, sizeof(buf));
    }
    if (BIT_CHECK(settings, INCLUDE_TIME))
    {
        char time[10];
        strftime(time, sizeof(time), "%H:%M:%S", now);
        AddWithSpaceIfNotEmpty(buf, time, sizeof(buf));
    }
    if (BIT_CHECK(settings, INCLUDE_DAY))
    {
        char day[10];
        strftime(day, sizeof(day), "%A", now);
        AddWithSpaceIfNotEmpty(buf, day, sizeof(buf));
    }
    if (BIT_CHECK(settings, UPPERCASE))
    {
        const char* ch = message;
        int index = 0;
        while (*ch != '\0')
        {
            message[index] = toupper(*ch);
            ch++;
            index++;
        }
        AddWithSpaceIfNotEmpty(buf, message, sizeof(buf));
    }
    else
    {
        AddWithSpaceIfNotEmpty(buf, message, sizeof(buf));
    }

    if (BIT_CHECK(settings, TO_CONSOLE))
    {
        printf("%s\n", buf);
    }
    if (BIT_CHECK(settings, TO_FILE))
    {
        FILE* f = fopen("log.txt", "a");
        fprintf(f, "%s\n", buf);
        fclose(f);
    }
}
void AddWithSpaceIfNotEmpty(char* chBuf, char* chWhat, size_t size)
{
    if (*chBuf != 0)
        strncat(chBuf, " ", size);
    strncat(chBuf, chWhat, size);
}
