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

void include_date(char* buffer, struct tm* now, size_t buffer_size);
void include_time(char* buffer, struct tm* now, size_t buffer_size);
void include_day(char* buffer, struct tm* now, size_t buffer_size);
void set_to_uppercase(char* message, char* buffer, size_t buffer_size);


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
        include_date(buf, now, sizeof(buf));
    }
    if (BIT_CHECK(settings, INCLUDE_TIME))
    {
        include_time(buf, now, sizeof(buf));
    }
    if (BIT_CHECK(settings, INCLUDE_DAY))
    {
        include_day(buf, now, sizeof(buf));
    }
    if (BIT_CHECK(settings, UPPERCASE))
    {
        set_to_uppercase(message, buf, sizeof(buf));
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
void include_date(char* buffer, struct tm* now, size_t buffer_size)
{
    char date[12];
    strftime(date, sizeof(date), "%Y-%m-%d", now);
    AddWithSpaceIfNotEmpty(buffer, date, buffer_size);
}
void include_time(char* buffer, struct tm* now, size_t buffer_size)
{
    char time[10];
    strftime(time, sizeof(time), "%H:%M:%S", now);
    AddWithSpaceIfNotEmpty(buffer, time, buffer_size);
}
void include_day(char* buffer, struct tm* now, size_t buffer_size)
{
    char day[10];
    strftime(day, sizeof(day), "%A", now);
    AddWithSpaceIfNotEmpty(buffer, day, buffer_size);
}
void set_to_uppercase(char* message, char* buffer, size_t buffer_size)
{
    const char* ch = message;

    while (*ch != '\0')
    {
        *(message++) = toupper(*(ch++));
    }
}