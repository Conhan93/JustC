#include <stdio.h>

#define BIT_CLEAR(a, b) ((a) &= ~(1 << b))

int main()
{
    unsigned char c = 128;

    BIT_CLEAR(c, 0);
    BIT_CLEAR(c, 2);
    BIT_CLEAR(c, 4);

    // 128 == 10000000 so no bytes are changed

    printf("Decimal value: %d", c);
}