#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
#include<math.h>
int main(void)
{
    int j, i = 0, letter = 0, space = 0, words, sentence = 0, Index;
    float index, L, s;
    string text = get_string("Text:");
    j = strlen(text);
    //printf("strlen is%d\n",j);
    for (i = 0; i < j; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter += 1;
        }

        if (text[i] == ' ')
        {
            space++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence += 1;
        }

    }
    words = space + 1;                                  //count words
    //printf("words are%d\n",words);
    //printf("Letters are%d\n",letter);
    //printf("sentences are%d\n",sentence);
    L = (100.0 * letter) / words;                         // length of letters
    s = (100.0 * sentence) / words;                       // length of sentences
    index = 0.0588 * L - 0.296 * s - 15.8;
    Index = round(index);
    //printf("index is%d\n",index);
    if (Index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Index);
    }

}