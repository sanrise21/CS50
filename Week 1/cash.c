#include<stdio.h>
#include<math.h>
#include<cs50.h>
int main(void)
{
    float dollars;
    int coins = 0;
    do
    {
        dollars = get_float("Change owed:");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    //printf("%d",cents);
    while (cents != 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
            coins++;
        }
        else if (cents >= 1)
        {
            cents = cents - 1;
            coins++;
        }


    }
    printf("%i\n", coins);


}