#include <stdio.h>
#include <math.h>

#define BASE 2


int main()
{
    char str[] = "00001001";

    int value = 0, position = 0, position_value = 0;

    for (int index = sizeof(str) - 2; index >= 0; index--)
    {
        // place in the string from the right
        position = (sizeof(str) - 2) - index;
        // if it's a 1 or 0
        position_value = str[index] - '0';
        // if 1, raise 2 to the position and add to value
        if (position_value)
            value += pow(BASE, position);

    }
    printf("\n%s equals %d", str, value);
}