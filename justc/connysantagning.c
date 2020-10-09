#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef int dice_rolls;

void roll_dice(dice_rolls* bonus_rolls, int* result);
int get_max_rolls();


void main() {
    system("chcp 65001"); // allows for swedish characters in cmdscreen(on win 10)
    srand(time(NULL)); // generates seed for dice rolls

    printf("\nSkrivet av Conny Hansson\n30/05-2020\n\n");

    char cmd = 'j';
    int result, max_rolls;
    dice_rolls actual_rolls, bonus_rolls;

    do
    {
        switch (cmd)
        {
        case 'j':
            result = 0;
            actual_rolls = 0;
            bonus_rolls = 0;

            max_rolls = get_max_rolls();

            do
            {

                roll_dice(&bonus_rolls, &result);
                actual_rolls++;
            } while (actual_rolls < max_rolls);

            printf("\nAlla tärningar har kastats.\nTotala summan är: %d och antalet kastningar är: %d\n", result, actual_rolls + bonus_rolls);
            break;
        case 'n':
            printf("\nAvslutar programmet");
            return;
        default:
            printf("\nFelaktig inmatning, försök igen\n");
            break;
        }
        printf("Vill du spela igen?(j/n): ");
        scanf(" %c%*c", &cmd);
    } while (1);

}
void roll_dice(dice_rolls* bonus_rolls, int* result) {
    int dice = 0;

    dice = rand() % 6 + 1;

    if (dice == 6) {
        printf("Du rullade sex, kastar två nya tärningar\n");
        roll_dice(bonus_rolls, result);
        roll_dice(bonus_rolls, result);
        (*bonus_rolls) += 2;
    }
    else
    {
        printf("Du rullade %d, summan av slagna tärningar är nu %d\n", dice, (*result) + dice);
        (*result) += dice;
    }

}

int get_max_rolls() {
    int max_rolls = 0;
    do {
        printf("Hur många tärningar vill du kasta?(min 1, max 5): ");
        scanf("%d", &max_rolls);
        if (max_rolls < 1 || max_rolls > 5)
            printf("Du angav ett felaktig antal, försök igen.\n");
    } while (max_rolls < 1 || max_rolls > 5);
    printf("\nKastar %d tärningar\n", max_rolls);
    return max_rolls;
}
