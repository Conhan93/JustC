#include <stdio.h>
#include <stdbool.h>

// bitshift by b amount and OR operation to set
#define BIT_SET(a, b) ((a) |= (1UL << b))
// bitshift by amount and use AND(assigned) to clear
#define BIT_CLEAR(a, b) ((a) &= ~(1UL << b))
// bitshift by b amount and use XOR to flip
#define BIT_FLIP(a, b) ((a) ^= (1UL << b))
// bitshift by b amount and use AND to check
#define BIT_CHECK(a, b) ((a) & (1UL << b))



void print_bits(int number);
void clear_bit(int* number);
void set_bit(int* number);
int choose_bit(int* bit_sel);

void print_number(int number) { printf("\nEntered number is now: %d", number); }

int main()
{
    while (true)
    {
        int number = 0;
        printf("\nEnter number: ");
        scanf(" %d%*c", &number);

        int sel = 0;
        printf("\n****choose operation****\n"
            "1. Print bits\n"
            "2. Clear bit\n"
            "3. Set bit\n");
        scanf(" %d", &sel);
        switch (sel)
        {
        case 1:
            print_bits(number);
            break;
        case 2:
            clear_bit(&number);
            print_number(number);
            break;
        case 3:
            set_bit(&number);
            print_number(number);
            break;
        default:
            printf("\nInvalid input!");
            break;
        }


    }

}
void print_bits(int number)
{
    // for loops, loops through the integer(32 bits) in reverse
    for (int digit = 31; digit >= 0; digit--)
    {
        // this just adds spaces every 8th bit, so every byte
        if (digit % 8 == 0 && (digit < 31 && digit > 0)) printf(" ");

        /*
            BIT_CHECK bit shifts it's way to the digith position in "number"
            and returns the value of that bit.

            I'm using a ternary operator(condition ? this if true : this if false)
            to convert that to a 1 or 0, any value except 0 is evaluated as true
            so it prints 1 if and the value 0 will print zero
        */
        printf("%d", BIT_CHECK(number, digit) ? 1 : 0);
    }
}
void clear_bit(int* number)
{
    int bit_sel = 0;

    // fetches bit you want to change
    choose_bit(&bit_sel);

    /*
        BIT_CLEAR bit shifts it's way to the position of bit_sel.
        then uses AND NOT(NAND) to clear the bit.

        so bit shifting like (1 << 3) gives us the value at the third bit(starting at 0)
        so 00000100 == 4

        then we might have a number like 6 == 00000110
        AND:ing these numbers gives us

        00000110 &= 00000100 == 00000110

        which isn't very useful because the bit we wanted to change(3rd is still there)
        but adding a negation operation NOT "~" allows us to apply a NOT operation to the bit
        we just retrieved and invert it.

        NOT 00000100 == 11111011
        then we AND them

        00000110 &= 11111011 == 00000100

        since the two bits differ, it'll be set to false or 0
        and thus it is cleared

        Also check out : https://en.wikipedia.org/wiki/NAND_gate
        what's important in that link is the outcomes in top right.
        since the bit we use from out bitshifting is always on(1)
        if the bit from the number is also on(1)

        it will be set off(set to 0)

    */
    BIT_CLEAR(*number, bit_sel);
}
void set_bit(int* number)
{
    int bit_sel = 0;
    choose_bit(&bit_sel);

    /*
        We bitwise shift to the position of bit_sel like in the last one
        But this time instead of inverting that bit and then AND:ing them(NAND)

        we're going to be using the OR operation.
        which always evaluates to 1 unless both bits are set 0
        1 | 1 == 1
        1 | 0 == 1
        0 | 1 == 1
        0 | 0 == 0
        since the bit we shifted to isn't set to zero, the effect
        is that the operation will always evaluate to 1 and the bit will set.
    */


    BIT_SET(*number, bit_sel);
}
int choose_bit(int* bit_sel)
{
    printf("\nSelect bit to access: ");
    scanf(" %d%*c", bit_sel);
}