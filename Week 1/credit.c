#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main(void)
{
    int count = 0, sum = 0, i, ld, rem, sum1 = 0, sum2 = 0, first, FIRST;
    long cn, cn1;
    long num = get_long("Number:");
    cn = num;
    cn1 = num;
    printf("\n");
    do                                                          //do loop
    {
        count++;
        cn = cn / 10;
    }
    while (cn != 0);                                            //check if card is valid

    if (count != 13 && count != 15 && count != 16)           //counting digits of card
    {
        printf("INVALID\n");
        return 0;
    }


    for (i = 0; i < count / 2; i++)                         // for loop to do different operations
    {
        rem = num % 10;
        sum1 = sum1 + rem;
        num = num / 10;
        ld = num % 10;
        if (ld * 2 >= 10)
        {
            sum2 = sum2 + ((ld * 2) / 10) + ((ld * 2) % 10);
        }
        else
        {
            sum2 = sum2 + ld * 2;
        }
        num = num / 10;
    }
    sum = sum1 + sum2 + num;
    if (sum % 10 == 0)
    {
        if (count == 15)                                                    // if condition to check if digits=15
        {
            first = cn1 / pow(10, 13);
            if (first == 34 || first == 37)
            {
                printf("AMEX");                                //check for amex card
            }
            else
            {
                printf("INVALID");
            }
        }
        else if (count == 16)                              // if condition to check if digits=16
        {
            first = cn1 / pow(10, 14);
            FIRST = cn1 / pow(10, 15);
            if (first == 51 || first == 52 || first == 53 || first == 54 || first == 55)
            {
                printf("MASTERCARD");                                     //check for mastercard
            }
            else if (FIRST == 4)
            {
                printf("VISA");                                             //check for visa
            }
            else
            {
                printf("INVALID");
            }
        }
        else if (count == 13)
        {
            first = cn1 / pow(10, 12);
            if (first == 4)
            {
                printf("VISA");
            }
            else
            {
                printf("INVALID");
            }
        }
    }
    else
    {
        printf("INVALID");
    }
    printf("\n");
}