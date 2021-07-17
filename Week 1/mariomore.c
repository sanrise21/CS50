#include<stdio.h>
#include<cs50.h>
int main()
{
    int i, j, q, n;
    do
    {
        i = get_int("Positive number: ");     // input a number between 1 and 8
    }
    while (i < 1 || i > 8);
    //printf("enter value\n");
    //scanf("%d",&i);
    for (j = 1; j <= i; j++)
    {
        for (q = 1; q <= i - j; q++)
        {
            printf(" ");
        }

        for (int temp = q; temp <= i; temp++)
        {
            printf("#");
        }
        printf("  ");
        for (int temp = q; temp <= i; temp++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}