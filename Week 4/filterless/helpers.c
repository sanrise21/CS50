#include "helpers.h"
#include<math.h>
//#include<stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    int final, i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed);
            average = average / 3;
            final = round(average);
            //printf("avergae is%f and final is %d",average,final);
            image[i][j].rgbtBlue = final;
            image[i][j].rgbtGreen = final;
            image[i][j].rgbtRed = final;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sred, sblue, sgreen;
    int final, i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            sblue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            sred = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sgreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if (sblue > 255)
            {
                sblue = 255;
            }
            if (sred > 255)
            {
                sred = 255;
            }
            if (sgreen > 255)
            {
                sgreen = 255;
            }

            image[i][j].rgbtRed = sred;
            image[i][j].rgbtGreen = sgreen;
            image[i][j].rgbtBlue = sblue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{


    int temp1, temp2, temp3, a, b, c, i, j, n;
    n = width;
    for (i = 0; i < height; i++)
    {
        a = b = c = 1;
        for (j = 0; j < width / 2; j++)
        {
            temp1 = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][n - a].rgbtRed;
            image[i][n - a].rgbtRed = temp1;
            a++;

            temp2 = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][n - b].rgbtBlue;
            image[i][n - b].rgbtBlue = temp2;
            b++;

            temp3 = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][n - c].rgbtGreen;
            image[i][n - c].rgbtGreen = temp3;
            c++;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, e, f, f1, f2, f3;
    float avgblue, avgred, avggreen ;
    RGBTRIPLE copy [height][width];





    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if ((i != (height - 1)) && (j != (width - 1)) && (j != 0) && (i != 0))      //MIDDLE PIXEL CHECK
            {

                avgblue = (copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue
                           + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                           copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue);

                avgred = (copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed
                          + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                          copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed);

                avggreen = (copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen
                            + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                            copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen);


                f1 = round(avgblue / 9);
                f2 = round(avgred / 9);
                f3 = round(avggreen / 9);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;


            }
            //FOR CORNERS
            if ((i == 0 && j == 0))
            {
                avgblue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue
                           + copy[i + 1][j + 1].rgbtBlue);

                avgred = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed
                          + copy[i + 1][j + 1].rgbtRed);

                avggreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen
                            + copy[i + 1][j + 1].rgbtGreen);



                f1 = round(avgblue / 4);
                f2 = round(avgred / 4);
                f3 = round(avggreen / 4);

                image[0][0].rgbtBlue = f1;
                image[0][0].rgbtRed = f2;
                image[0][0].rgbtGreen = f3;



            }
            else if (i == (height - 1) && j == 0)
            {
                avgblue = (copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue
                           + copy[i][j + 1].rgbtBlue);

                avgred = (copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed
                          + copy[i][j + 1].rgbtRed);

                avggreen = (copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen
                            + copy[i][j + 1].rgbtGreen);



                f1 = round(avgblue / 4);
                f2 = round(avgred / 4);
                f3 = round(avggreen / 4);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }
            else if (i == 0 && j == (width - 1))
            {
                avgblue = (copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue
                           + copy[i + 1][j].rgbtBlue);

                avgred = (copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed
                          + copy[i + 1][j].rgbtRed);

                avggreen = (copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen
                            + copy[i + 1 ][j].rgbtGreen);



                f1 = round(avgblue / 4);
                f2 = round(avgred / 4);
                f3 = round(avggreen / 4);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }
            else if (j == (width - 1) && i == (height - 1))
            {
                avgblue = (copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue
                           + copy[i][j].rgbtBlue);

                avgred = (copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed
                          + copy[i][j].rgbtRed);

                avggreen = (copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen
                            + copy[i][j].rgbtGreen);



                f1 = round(avgblue / 4);
                f2 = round(avgred / 4);
                f3 = round(avggreen / 4);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }

            //FOR EDGES
            if ((i != 0) && (i != (height - 1)) && (j == (width - 1)))               // condition to check 1 edge
            {
                avgblue = (copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue
                           + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue);

                avgred = (copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j].rgbtRed
                          + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed);

                avggreen = (copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen
                            + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen);



                f1 = round(avgblue / 6);
                f2 = round(avgred / 6);
                f3 = round(avggreen / 6);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }
            else if ((i != 0) && (i != (height - 1)) && j == 0)
            {
                avgblue = (copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue
                           + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue);

                avgred = (copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed
                          + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed);

                avggreen = (copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen
                            + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen);



                f1 = round(avgblue / 6);
                f2 = round(avgred / 6);
                f3 = round(avggreen / 6);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }
            else if ((i == 0) && (j != 0) && (j != (width - 1)))
            {
                avgblue = (copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue
                           + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue);

                avgred = (copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i][j].rgbtRed
                          + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed);

                avggreen = (copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen
                            + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen);



                f1 = round(avgblue / 6);
                f2 = round(avgred / 6);
                f3 = round(avggreen / 6);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }
            else if ((i == (height - 1)) && (j != 0) && (j != (width - 1)))
            {
                avgblue = (copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue
                           + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue);

                avgred = (copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j].rgbtRed
                          + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed);

                avggreen = (copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen
                            + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen);



                f1 = round(avgblue / 6);
                f2 = round(avgred / 6);
                f3 = round(avggreen / 6);

                image[i][j].rgbtBlue = f1;
                image[i][j].rgbtRed = f2;
                image[i][j].rgbtGreen = f3;
            }
        }
    }




    return;
}
