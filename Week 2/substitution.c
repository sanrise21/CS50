#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(int argc, string argv[])
{
    int i, j;
    char match;
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    int len1, len2, count;
    len1 = strlen(argv[1]);
    if (len1 != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    for (i = 0; i < 26; i++)
    {
        if (!((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')))
        {
            //printf("usage");
            return 1;
        }

    }

    for (i = 0; i < 26; i++)
    {
        for (j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("%c\n", argv[1][j]);
                //printf("usage1");
                return 1;
            }
        }
    }

    string plain = get_string("plaintext:  ");
    len2 = strlen(plain);
    //printf("len2 is %i\n",len2);
    printf("ciphertext: ");
    for (i = 0; i < len2; i++)
    {
        count = 0;
        if (!((plain[i] >= 'a' && plain[i] <= 'z') || (plain[i] >= 'A' && plain[i] <= 'Z')))
        {
            printf("%c", plain[i]);

        }
        else if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            count = 0;
            for (match = 'a'; match <= 'z'; match ++)
            {
                if (plain[i] != match)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (islower(plain[i]))
            {
                printf("%c", tolower(argv[1][count]));
            }
            else
            {
                printf("%c", argv[1][count]);
            }
        }
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            count = 0;
            for (match = 'A'; match <= 'Z'; match ++)
            {
                if (plain[i] != match)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (isupper(plain[i]))
            {
                printf("%c", toupper(argv[1][count]));
            }
            else
            {
                printf("%c", argv[1][count]);
            }

        }
    }
    printf("\n");
}