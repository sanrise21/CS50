#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int n, i, j;                               //variables declared
    do
    {
        n = get_int("Positive number: ");     // input a number between 1 and 8
    }
    while (n < 1 || n > 8);

    for (i = 0; i < n; i++)                         //1st for loop
    {

        for (j = 1; j < n - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)                         //printing#
        {
            printf("#");                      // print #
        }
        printf("\n");
    }
}

