#include <stdio.h>
#include <time.h>

#define TIMELEN 100

int main(void)
{
    struct tm* now;
    time_t time_var = time(NULL);
    char time_string[TIMELEN];
    now = localtime(&time_var);

    strftime(time_string, sizeof(time_string), "%d-%m-%Y", now);

    printf("\n1. short %s", time_string);



    strftime(time_string, sizeof(time_string), "%d-%m-%Y %H:%M:%S", now);
    printf("\n1. complete %s", time_string);

    // labb2
    // time.h doesn't save milliseconds
    printf("\n2.");
    printf("\nyear = %d", now->tm_year);
    printf("\nmonth = %d", now->tm_mon);
    printf("\nday = %d", now->tm_mday);
    printf("\nhour = %d", now->tm_hour);
    printf("\nminute = %d", now->tm_min);
    printf("\nsecond= %d", now->tm_sec);

    //labb3

    strftime(time_string, sizeof(time_string), "The day of the week for %x is %A", now);
    printf("\n3. %s", time_string);

    strftime(time_string, sizeof(time_string), "The day of the wek for %Y-%m-%d is %A", now);
    printf("\n3. svensk variant - %s", time_string);

    //labb4

    struct tm* time4;
    time_t calendar = time(NULL);

    time4 = localtime(&calendar);

    time4->tm_mday += 40;
    mktime(time4);

    strftime(time_string, sizeof(time_string), "%x", time4);
    printf("\n4. %s", time_string);

    //labb5
    time_t calendar5 = time(NULL);
    struct tm* time5 = localtime(&calendar5);

    for (int iteration = 1; iteration <= 10; iteration++)
    {
        time5->tm_mday += 40;
        mktime(time5);
        strftime(time_string, sizeof(time_string), "%x", time5);
        printf("\n5.%d %s", iteration, time_string);
    }



    //labb6
    struct tm* time6;
    time_t calendar_time = time(NULL);
    time6 = localtime(&calendar_time);


    int year = 0, month = 0, day = 0;

    printf("\nEnter date in (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &year, &month, &day);

    time6->tm_mday = day;
    time6->tm_mon = month - 1; // -1 because months are 0-11 instead of 1-12
    time6->tm_year = year - 1900; // because tm_year == years since 1900



    strftime(time_string, sizeof(time_string), "%x", time6);
    printf("\n6. %s", time_string);

    //labb7
    // what?



    //labb8


}