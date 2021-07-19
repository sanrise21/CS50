#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
bool check_for_key(string s);
int main(int argc, string argv[])
{

    int i, len;
    //len=strlen(argv[1]);


    if (argc != 2 || !check_for_key(argv[1]))
    {
        printf("Usage: ./caesar key");
        printf("\n");
        return 1;

    }





    int key = atoi(argv[1]);
    string plain = get_string("Plaintext:");
    printf("ciphertext: ");
    for (i = 0; i < strlen(plain); i++)
    {
        char c = plain[i];
        if (isalpha(c))
        {
            char m = 'a';
            if (isupper(c))
            {
                m = 'A';
            }
            printf("%c", (c - m + key) % 26 + m);


        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");


}

bool check_for_key(string s)
{
    for (int i = 0; i < strlen(s); i++)

        if (!isdigit(s[i]))
        {
            return false;
        }

    return true;
}