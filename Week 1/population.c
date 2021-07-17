#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n, end, year = 0;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);

    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < n);

    // TODO: Calculate number of years until we reach threshold
    if (n == end)
    {
        year = 0;
    }
    else
    {
        do
        {
            n = n + (n / 3) - (n / 4);
            year++;
        }
        while (n < end);
    }



    // TODO: Print number of years
    printf("Years: %d\n", year);

}
