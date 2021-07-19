#include "helpers.h"
#include<math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, avg;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, k, temp;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            k = width - 1 - j;
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][k].rgbtRed = temp;
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][k].rgbtGreen = temp;
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][k].rgbtBlue = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, b, g, avgblue, avgred, avggreen, r, m, n, count;

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
            r = g = b = count = 0;
            for (m = i - 1; m <= i + 1; m++)
            {
                if (m == height)
                {
                    break;
                }
                if (m < 0)
                {
                    continue;
                }

                for (n = j - 1; n <= j + 1; n++)
                {
                    if (n == height)
                    {
                        break;
                    }
                    if (n < 0)
                    {
                        continue;
                    }


                    r = r + copy[m][n].rgbtRed;
                    g = g + copy[m][n].rgbtGreen;
                    b = b + copy[m][n].rgbtBlue;
                    count ++;
                }
            }


            avgred = round(r / (float) count);
            avggreen = round(g / (float) count);
            avgblue = round(b / (float) count);


            image[i][j].rgbtBlue = avgblue;
            image[i][j].rgbtRed = avgred;
            image[i][j].rgbtGreen = avggreen;
        }
    }

















    /*for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if ((i != (height - 1)) && (j != (width - 1)) && (j != 0) && (i != 0))      //MIDDLE PIXEL CHECK
            {

                avgblue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue
                                 + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                 copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 9.0);

                avgred = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed
                                + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 9.0);

                avggreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen
                                  + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                  copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 9.0);




                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;


            }
            //FOR CORNERS
            if ((i == 0 && j == 0))
            {
                avgblue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue
                                 + copy[i + 1][j + 1].rgbtBlue) / 4.0);

                avgred = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed
                                + copy[i + 1][j + 1].rgbtRed) / 4.0);

                avggreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen
                                  + copy[i + 1][j + 1].rgbtGreen) / 4.0);

                image[0][0].rgbtBlue = avgblue;
                image[0][0].rgbtRed = avgred;
                image[0][0].rgbtGreen = avggreen;



            }
            else if (i == (height - 1) && j == 0)
            {
                avgblue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue
                                 + copy[i][j + 1].rgbtBlue) / 4.0);

                avgred = round((copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed
                                + copy[i][j + 1].rgbtRed) / 4.0);

                avggreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen
                                  + copy[i][j + 1].rgbtGreen) / 4.0);


                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }
            else if (i == 0 && j == (width - 1))
            {
                avgblue = round((copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue
                                 + copy[i + 1][j].rgbtBlue) / 4.0);

                avgred = round((copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed
                                + copy[i + 1][j].rgbtRed) / 4.0);

                avggreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen
                                  + copy[i + 1 ][j].rgbtGreen) / 4.0);


                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }
            else if (j == (width - 1) && i == (height - 1))
            {
                avgblue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue
                                 + copy[i][j].rgbtBlue) / 4.0);

                avgred = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed
                                + copy[i][j].rgbtRed) / 4.0);

                avggreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen
                                  + copy[i][j].rgbtGreen) / 4.0);


                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }

            //FOR EDGES
            if ((i != 0) && (i != (height - 1)) && (j == (width - 1)))               // condition to check 1 edge
            {
                avgblue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue
                                 + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 6.0);

                avgred = round((copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j].rgbtRed
                                + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 6.0);

                avggreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen
                                  + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 6.0);


                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }
            else if ((i != 0) && (i != (height - 1)) && j == 0)
            {
                avgblue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue
                                 + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);

                avgred = round((copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed
                                + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);

                avggreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen
                                  + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);




                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }
            else if ((i == 0) && (j != 0) && (j != (width - 1)))
            {
                avgblue = round((copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue
                                 + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);

                avgred = round((copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i][j].rgbtRed
                                + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);

                avggreen = round((copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen
                                  + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);



                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }
            else if ((i == (height - 1)) && (j != 0) && (j != (width - 1)))
            {
                avgblue = round((copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue
                                 + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 6.0);

                avgred = round((copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j].rgbtRed
                                + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);

                avggreen = round((copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen
                                  + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 6.0);



                image[i][j].rgbtBlue = avgblue;
                image[i][j].rgbtRed = avgred;
                image[i][j].rgbtGreen = avggreen;
            }
        }
    }*/

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int i, j, e, f, k1, k2, m, n, count;
    int gxr, gyr, gxb, gyb, gxg, gyg;
    float r, b, g;


    RGBTRIPLE copy [height][width];




    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};





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
            k1 = 1 - i;
            if (k1 < 0)
            {
                k1 = 0;
            }
            count = 1;


            gxr = gyr = gxg = gyg = gxb = gyb = r = g = b = 0;
            for (m = i - 1; m <= i + 1; m++)
            {



                if (count != 1)
                {
                    k1 ++;
                }

                if (m < 0)
                {
                    continue;
                }


                k2 = 1 - j;
                if (k2 < 0)
                {
                    k2 = 0;
                }
                if (m == height)
                {
                    break;
                }
                n = j - 1;
                if (n < 0)
                {
                    n++;
                }






                while (k1 < height && k2 < height && n <= j + 1)
                {


                    if (n == height)
                    {
                        break;
                    }

                    gxr = gxr + (copy[m][n].rgbtRed * gx[k1][k2]);
                    gxg = gxg + (copy[m][n].rgbtGreen * gx[k1][k2]);
                    gxb = gxb + (copy[m][n].rgbtBlue * gx[k1][k2]);


                    gyr = gyr + (copy[m][n].rgbtRed * gy[k1][k2]);
                    gyg = gyg + (copy[m][n].rgbtGreen * gy[k1][k2]);
                    gyb = gyb + (copy[m][n].rgbtBlue * gy[k1][k2]);

                    n++;
                    k2++;

                }

                count++;
            }


            b = sqrt(gxb * gxb + gyb * gyb);
            r = sqrt(gxr * gxr + gyr * gyr);
            g = sqrt(gxg * gxg + gyg * gyg);

            if (b > 255.0)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(b);
            }

            if (r > 255.0)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(r);
            }

            if (g > 255.0)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(g);
            }
        }
    }






    /*for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int gxblue = 0, gyblue = 0, gxred = 0, gyred = 0, gxgreen = 0, gygreen = 0;
            if ((i != (height - 1)) && (j != (width - 1)) && (j != 0) && (i != 0))      //MIDDLE PIXEL CHECK
            {

                gxblue = copy[i - 1][j - 1].rgbtBlue * gx[0][0] + copy[i - 1][j].rgbtBlue * gx[0][1] + copy[i - 1][j + 1].rgbtBlue * gx[0][2]
                         + copy[i][j - 1].rgbtBlue * gx[1][0] + copy[i][j].rgbtBlue * gx[1][1] + copy[i][j + 1].rgbtBlue * gx[1][2] +
                         copy[i + 1][j - 1].rgbtBlue * gx[2][0] + copy[i + 1][j].rgbtBlue * gx[2][1] + copy[i + 1][j + 1].rgbtBlue * gx[2][2];


                gyblue = copy[i - 1][j - 1].rgbtBlue * gy[0][0] + copy[i - 1][j].rgbtBlue * gy[0][1] + copy[i - 1][j + 1].rgbtBlue * gy[0][2]
                         + copy[i][j - 1].rgbtBlue * gy[1][0] + copy[i][j].rgbtBlue * gy[1][1] + copy[i][j + 1].rgbtBlue * gy[1][2] +
                         copy[i + 1][j - 1].rgbtBlue * gy[2][0] + copy[i + 1][j].rgbtBlue * gy[2][1] + copy[i + 1][j + 1].rgbtBlue * gy[2][2];


                gxred = copy[i - 1][j - 1].rgbtRed * gx[0][0] + copy[i - 1][j].rgbtRed * gx[0][1] + copy[i - 1][j + 1].rgbtRed * gx[0][2]
                        + copy[i][j - 1].rgbtRed * gx[1][0] + copy[i][j].rgbtRed * gx[1][1] + copy[i][j + 1].rgbtRed * gx[1][2] +
                        copy[i + 1][j - 1].rgbtRed * gx[2][0] + copy[i + 1][j].rgbtRed * gx[2][1] + copy[i + 1][j + 1].rgbtRed * gx[2][2];



                gyred = copy[i - 1][j - 1].rgbtRed * gy[0][0] + copy[i - 1][j].rgbtRed * gy[0][1] + copy[i - 1][j + 1].rgbtRed * gy[0][2]
                        + copy[i][j - 1].rgbtRed * gy[1][0] + copy[i][j].rgbtRed * gy[1][1] + copy[i][j + 1].rgbtRed * gy[1][2] +
                        copy[i + 1][j - 1].rgbtRed * gy[2][0] + copy[i + 1][j].rgbtRed * gy[2][1] + copy[i + 1][j + 1].rgbtRed * gy[2][2];




                gxgreen = copy[i - 1][j - 1].rgbtGreen * gx[0][0] + copy[i - 1][j].rgbtGreen * gx[0][1] + copy[i - 1][j + 1].rgbtGreen * gx[0][2]
                          + copy[i][j - 1].rgbtGreen * gx[1][0] + copy[i][j].rgbtGreen * gx[1][1] + copy[i][j + 1].rgbtGreen * gx[1][2] +
                          copy[i + 1][j - 1].rgbtGreen * gx[2][0] + copy[i + 1][j].rgbtGreen * gx[2][1] + copy[i + 1][j + 1].rgbtGreen * gx[2][2];


                gygreen = copy[i - 1][j - 1].rgbtGreen * gy[0][0] + copy[i - 1][j].rgbtGreen * gy[0][1] + copy[i - 1][j + 1].rgbtGreen * gy[0][2]
                          + copy[i][j - 1].rgbtGreen * gy[1][0] + copy[i][j].rgbtGreen * gy[1][1] + copy[i][j + 1].rgbtGreen * gy[1][2] +
                          copy[i + 1][j - 1].rgbtGreen * gy[2][0] + copy[i + 1][j].rgbtGreen * gy[2][1] + copy[i + 1][j + 1].rgbtGreen * gy[2][2];



                image[i][j].rgbtBlue = round(sqrt(gxblue * gxblue + gyblue * gyblue));
                image[i][j].rgbtRed = round(sqrt(gxred * gxred + gyred * gyred));
                image[i][j].rgbtGreen = round(sqrt(gxgreen * gxgreen + gygreen * gygreen));


            }
            //FOR CORNERS
            if ((i == 0 && j == 0))
            {
                gxblue = copy[i][j].rgbtBlue * gx[1][1] + copy[i][j + 1].rgbtBlue * gx[1][2]  + copy[i + 1][j].rgbtBlue * gx[2][1]
                         + copy[i + 1][j + 1].rgbtBlue * gx[2][2];


                gyblue = copy[i][j].rgbtBlue * gy[1][1] + copy[i][j + 1].rgbtBlue * gy[1][2]  + copy[i + 1][j].rgbtBlue * gy[2][1]
                         + copy[i + 1][j + 1].rgbtBlue * gy[2][2];

                gxred = copy[i][j].rgbtRed * gx[1][1] + copy[i][j + 1].rgbtRed * gx[1][2]  + copy[i + 1][j].rgbtRed * gx[2][1]
                        + copy[i + 1][j + 1].rgbtRed * gx[2][2];


                gyred = copy[i][j].rgbtRed * gy[1][1] + copy[i][j + 1].rgbtRed * gy[1][2]  + copy[i + 1][j].rgbtRed * gy[2][1]
                        + copy[i + 1][j + 1].rgbtRed * gy[2][2];
                gxgreen = copy[i][j].rgbtGreen * gx[1][1] + copy[i][j + 1].rgbtGreen * gx[1][2]  + copy[i + 1][j].rgbtGreen * gx[2][1]
                          + copy[i + 1][j + 1].rgbtGreen * gx[2][2];


                gygreen = copy[i][j].rgbtGreen * gy[1][1] + copy[i][j + 1].rgbtGreen * gy[1][2]  + copy[i + 1][j].rgbtGreen * gy[2][1]
                          + copy[i + 1][j + 1].rgbtGreen * gy[2][2];




                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[0][0].rgbtBlue = 255;
                }
                else
                {
                    image[0][0].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[0][0].rgbtRed = 255;
                }
                else
                {
                    image[0][0].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[0][0].rgbtGreen = 255;
                }
                else
                {
                    image[0][0].rgbtGreen = round(g);
                }



            }
            else if (i == (height - 1) && j == 0)
            {
                gxblue = copy[i - 1][j].rgbtBlue * gx[0][1] + copy[i - 1][j + 1].rgbtBlue * gx[0][2] + copy[i][j].rgbtBlue * gx[1][1]
                         + copy[i][j + 1].rgbtBlue * gx[1][2];


                gyblue = copy[i - 1][j].rgbtBlue * gy[0][1] + copy[i - 1][j + 1].rgbtBlue * gy[0][2] + copy[i][j].rgbtBlue * gy[1][1]
                         + copy[i][j + 1].rgbtBlue * gy[1][2];

                gxred = copy[i - 1][j].rgbtRed * gx[0][1] + copy[i - 1][j + 1].rgbtRed * gx[0][2] + copy[i][j].rgbtRed * gx[1][1]
                        + copy[i][j + 1].rgbtRed * gx[1][2];

                gyred = copy[i - 1][j].rgbtRed * gy[0][1] + copy[i - 1][j + 1].rgbtRed * gy[0][2] + copy[i][j].rgbtRed * gy[1][1]
                        + copy[i][j + 1].rgbtRed * gy[1][2];

                gxgreen = copy[i - 1][j].rgbtGreen * gx[0][1] + copy[i - 1][j + 1].rgbtGreen * gx[0][2] + copy[i][j].rgbtGreen * gx[1][1]
                          + copy[i][j + 1].rgbtGreen * gx[1][2];


                gygreen = copy[i - 1][j].rgbtGreen * gy[0][1] + copy[i - 1][j + 1].rgbtGreen * gy[0][2] + copy[i][j].rgbtGreen * gy[1][1]
                          + copy[i][j + 1].rgbtGreen * gy[1][2];


                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }


            }
            else if (i == 0 && j == (width - 1))
            {
                gxblue = copy[i][j - 1].rgbtBlue * gx[1][0] + copy[i][j].rgbtBlue * gx[1][1] + copy[i + 1][j - 1].rgbtBlue * gx[2][0]
                         + copy[i + 1][j].rgbtBlue * gx[2][1];


                gyblue = copy[i][j - 1].rgbtBlue * gy[1][0] + copy[i][j].rgbtBlue * gy[1][1] + copy[i + 1][j - 1].rgbtBlue * gy[2][0]
                         + copy[i + 1][j].rgbtBlue * gy[2][1];

                gxred = copy[i][j - 1].rgbtRed * gx[1][0] + copy[i][j].rgbtRed * gx[1][1] + copy[i + 1][j - 1].rgbtRed * gx[2][0]
                        + copy[i + 1][j].rgbtRed * gx[2][1];


                gyred = copy[i][j - 1].rgbtRed * gy[1][0] + copy[i][j].rgbtRed * gy[1][1] + copy[i + 1][j - 1].rgbtRed * gy[2][0]
                        + copy[i + 1][j].rgbtRed * gy[2][1];

                gxgreen = copy[i][j - 1].rgbtGreen * gx[1][0] + copy[i][j].rgbtGreen * gx[1][1] + copy[i + 1][j - 1].rgbtGreen * gx[2][0]
                          + copy[i + 1 ][j].rgbtGreen * gx[2][1];

                gygreen = copy[i][j - 1].rgbtGreen * gy[1][0] + copy[i][j].rgbtGreen * gy[1][1] + copy[i + 1][j - 1].rgbtGreen * gy[2][0]
                          + copy[i + 1 ][j].rgbtGreen * gy[2][1];


                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }
            }
            else if (j == (width - 1) && i == (height - 1))
            {
                gxblue = copy[i - 1][j - 1].rgbtBlue * gx[0][0] + copy[i - 1][j].rgbtBlue * gx[0][1] + copy[i][j - 1].rgbtBlue * gx[1][0]
                         + copy[i][j].rgbtBlue * gx[1][1];


                gyblue = copy[i - 1][j - 1].rgbtBlue * gy[0][0] + copy[i - 1][j].rgbtBlue * gy[0][1] + copy[i][j - 1].rgbtBlue * gy[1][0]
                         + copy[i][j].rgbtBlue * gy[1][1];

                gxred = copy[i - 1][j - 1].rgbtRed * gx[0][0] + copy[i - 1][j].rgbtRed * gx[0][1] + copy[i][j - 1].rgbtRed * gx[1][0]
                        + copy[i][j].rgbtRed * gx[1][1];


                gyred = copy[i - 1][j - 1].rgbtRed * gy[0][0] + copy[i - 1][j].rgbtRed * gy[0][1] + copy[i][j - 1].rgbtRed * gy[1][0]
                        + copy[i][j].rgbtRed * gy[1][1];

                gxgreen = copy[i - 1][j - 1].rgbtGreen * gx[0][0] + copy[i - 1][j].rgbtGreen * gx[0][1] + copy[i][j - 1].rgbtGreen * gx[1][0]
                          + copy[i][j].rgbtGreen * gx[1][1];

                gygreen = copy[i - 1][j - 1].rgbtGreen * gx[0][0] + copy[i - 1][j].rgbtGreen * gy[0][1] + copy[i][j - 1].rgbtGreen * gy[1][0]
                          + copy[i][j].rgbtGreen * gy[1][1];



                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }
            }

            //FOR EDGES
            if ((i != 0) && (i != (height - 1)) && (j == (width - 1)))               // condition to check 1 edge
            {
                gxblue = copy[i - 1][j].rgbtBlue * gx[0][1] + copy[i - 1][j - 1].rgbtBlue * gx[0][0] + copy[i][j].rgbtBlue * gx[1][1]
                         + copy[i][j - 1].rgbtBlue * gx[1][0] + copy[i + 1][j].rgbtBlue * gx[2][1] + copy[i + 1][j - 1].rgbtBlue * gx[2][0];


                gyblue = copy[i - 1][j].rgbtBlue * gy[0][1] + copy[i - 1][j - 1].rgbtBlue * gy[0][0] + copy[i][j].rgbtBlue * gy[1][1]
                         + copy[i][j - 1].rgbtBlue * gy[1][0] + copy[i + 1][j].rgbtBlue * gy[2][1] + copy[i + 1][j - 1].rgbtBlue * gy[2][0];


                gxred = copy[i - 1][j].rgbtRed * gx[0][1] + copy[i - 1][j - 1].rgbtRed * gx[0][0] + copy[i][j].rgbtRed * gx[1][1]
                        + copy[i][j - 1].rgbtRed * gx[1][0] + copy[i + 1][j].rgbtRed * gx[2][1] + copy[i + 1][j - 1].rgbtRed * gx[2][0];


                gyred = copy[i - 1][j].rgbtRed * gy[0][1] + copy[i - 1][j - 1].rgbtRed * gy[0][0] + copy[i][j].rgbtRed * gy[1][1]
                        + copy[i][j - 1].rgbtRed * gy[1][0] + copy[i + 1][j].rgbtRed * gy[2][1] + copy[i + 1][j - 1].rgbtRed * gy[2][0];




                gxgreen = copy[i - 1][j].rgbtGreen * gx[0][1] + copy[i - 1][j - 1].rgbtGreen * gx[0][0] + copy[i][j].rgbtGreen * gx[1][1]
                          + copy[i][j - 1].rgbtGreen * gx[1][0] + copy[i + 1][j].rgbtGreen * gx[2][1] + copy[i + 1][j - 1].rgbtGreen * gx[2][0];



                gygreen = copy[i - 1][j].rgbtGreen * gy[0][1] + copy[i - 1][j - 1].rgbtGreen * gy[0][0] + copy[i][j].rgbtGreen * gy[1][1]
                          + copy[i][j - 1].rgbtGreen * gy[1][0] + copy[i + 1][j].rgbtGreen * gy[2][1] + copy[i + 1][j - 1].rgbtGreen * gy[2][0];






                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }
            }
            else if ((i != 0) && (i != (height - 1)) && j == 0)
            {
                gxblue = copy[i - 1][j].rgbtBlue * gx[0][1] + copy[i - 1][j + 1].rgbtBlue * gx[0][2] + copy[i][j].rgbtBlue * gx[1][1]
                         + copy[i][j + 1].rgbtBlue * gx[1][2] + copy[i + 1][j].rgbtBlue * gx[2][1] + copy[i + 1][j + 1].rgbtBlue * gx[2][2];




                gyblue = copy[i - 1][j].rgbtBlue * gy[0][1] + copy[i - 1][j + 1].rgbtBlue * gy[0][2] + copy[i][j].rgbtBlue * gy[1][1]
                         + copy[i][j + 1].rgbtBlue * gy[1][2] + copy[i + 1][j].rgbtBlue * gy[2][1] + copy[i + 1][j + 1].rgbtBlue * gy[2][2];

                gxred = copy[i - 1][j].rgbtRed * gx[0][1] + copy[i - 1][j + 1].rgbtRed * gx[0][2] + copy[i][j].rgbtRed * gx[1][1]
                        + copy[i][j + 1].rgbtRed * gx[1][2] + copy[i + 1][j].rgbtRed * gx[2][1] + copy[i + 1][j + 1].rgbtRed * gx[2][2];


                gyred = copy[i - 1][j].rgbtRed * gy[0][1] + copy[i - 1][j + 1].rgbtRed * gy[0][2] + copy[i][j].rgbtRed * gy[1][1]
                        + copy[i][j + 1].rgbtRed * gy[1][2] + copy[i + 1][j].rgbtRed * gy[2][1] + copy[i + 1][j + 1].rgbtRed * gy[2][2];

                gxgreen = copy[i - 1][j].rgbtGreen * gx[0][1] + copy[i - 1][j + 1].rgbtGreen * gx[0][2] + copy[i][j].rgbtGreen * gx[1][1]
                          + copy[i][j + 1].rgbtGreen * gx[1][2] + copy[i + 1][j].rgbtGreen * gx[2][1] + copy[i + 1][j + 1].rgbtGreen * gx[2][2];



                gygreen = copy[i - 1][j].rgbtGreen * gy[0][1] + copy[i - 1][j + 1].rgbtGreen * gy[0][2] + copy[i][j].rgbtGreen * gy[1][1]
                          + copy[i][j + 1].rgbtGreen * gy[1][2] + copy[i + 1][j].rgbtGreen * gy[2][1] + copy[i + 1][j + 1].rgbtGreen * gy[2][2];




                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }
            }
            else if ((i == 0) && (j != 0) && (j != (width - 1)))
            {
                gxblue = copy[i][j - 1].rgbtBlue * gx[1][0] + copy[i + 1][j - 1].rgbtBlue * gx[2][0] + copy[i][j].rgbtBlue * gx[1][1]
                         + copy[i + 1][j].rgbtBlue * gx[2][1] + copy[i][j + 1].rgbtBlue * gx[1][2] + copy[i + 1][j + 1].rgbtBlue * gx[2][2];



                gyblue = copy[i][j - 1].rgbtBlue * gy[1][0] + copy[i + 1][j - 1].rgbtBlue * gy[2][0] + copy[i][j].rgbtBlue * gy[1][1]
                         + copy[i + 1][j].rgbtBlue * gy[2][1] + copy[i][j + 1].rgbtBlue * gy[1][2] + copy[i + 1][j + 1].rgbtBlue * gy[2][2];

                gxred = copy[i][j - 1].rgbtRed * gx[1][0] + copy[i + 1][j - 1].rgbtRed * gx[2][0] + copy[i][j].rgbtRed * gx[1][1]
                        + copy[i + 1][j].rgbtRed * gx[2][1] + copy[i][j + 1].rgbtRed * gx[1][2] + copy[i + 1][j + 1].rgbtRed * gx[2][2];


                gyred = copy[i][j - 1].rgbtRed * gy[1][0] + copy[i + 1][j - 1].rgbtRed * gy[2][0] + copy[i][j].rgbtRed * gy[1][1]
                        + copy[i + 1][j].rgbtRed * gy[2][1] + copy[i][j + 1].rgbtRed * gy[1][2] + copy[i + 1][j + 1].rgbtRed * gy[2][2];

                gxgreen = copy[i][j - 1].rgbtGreen * gx[1][0] + copy[i + 1][j - 1].rgbtGreen * gx[2][0] + copy[i][j].rgbtGreen * gx[1][1]
                          + copy[i + 1][j].rgbtGreen * gx[2][1] + copy[i][j + 1].rgbtGreen * gx[1][2] + copy[i + 1][j + 1].rgbtGreen * gx[2][2];


                gygreen = copy[i][j - 1].rgbtGreen * gy[1][0] + copy[i + 1][j - 1].rgbtGreen * gy[2][0] + copy[i][j].rgbtGreen * gy[1][1]
                          + copy[i + 1][j].rgbtGreen * gy[2][1] + copy[i][j + 1].rgbtGreen * gy[1][2] + copy[i + 1][j + 1].rgbtGreen * gy[2][2];



                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }
            }
            else if ((i == (height - 1)) && (j != 0) && (j != (width - 1)))
            {
                gyblue = copy[i][j - 1].rgbtBlue * gy[1][0] + copy[i - 1][j - 1].rgbtBlue * gy[0][0] + copy[i][j].rgbtBlue * gy[1][1]
                         + copy[i - 1][j].rgbtBlue * gy[0][1] + copy[i][j + 1].rgbtBlue * gy[1][2] + copy[i - 1][j + 1].rgbtBlue * gy[0][2];


                gxblue = copy[i][j - 1].rgbtBlue * gx[1][0] + copy[i - 1][j - 1].rgbtBlue * gx[0][0] + copy[i][j].rgbtBlue * gx[1][1]
                         + copy[i - 1][j].rgbtBlue * gx[0][1] + copy[i][j + 1].rgbtBlue * gx[1][2] + copy[i - 1][j + 1].rgbtBlue * gx[0][2];

                gxred = copy[i][j - 1].rgbtRed * gx[1][0] + copy[i - 1][j - 1].rgbtRed * gx[0][0] + copy[i][j].rgbtRed * gx[1][1]
                        + copy[i - 1][j].rgbtRed * gx[0][1] + copy[i][j + 1].rgbtRed * gx[1][2] + copy[i - 1][j + 1].rgbtRed * gx[0][2];


                gyred = copy[i][j - 1].rgbtRed * gy[1][0] + copy[i - 1][j - 1].rgbtRed * gy[0][0] + copy[i][j].rgbtRed * gy[1][1]
                        + copy[i - 1][j].rgbtRed * gy[0][1] + copy[i][j + 1].rgbtRed * gy[1][2] + copy[i - 1][j + 1].rgbtRed * gy[0][2];

                gxgreen = copy[i][j - 1].rgbtGreen * gx[1][0] + copy[i - 1][j - 1].rgbtGreen * gx[0][0] + copy[i][j].rgbtGreen * gx[1][1]
                          + copy[i - 1][j].rgbtGreen * gx[0][1] + copy[i][j + 1].rgbtGreen * gx[1][2] + copy[i - 1][j + 1].rgbtGreen * gx[0][2];



                gygreen = copy[i][j - 1].rgbtGreen * gy[1][0] + copy[i - 1][j - 1].rgbtGreen * gy[0][0] + copy[i][j].rgbtGreen * gy[1][1]
                          + copy[i - 1][j].rgbtGreen * gy[0][1] + copy[i][j + 1].rgbtGreen * gy[1][2] + copy[i - 1][j + 1].rgbtGreen * gy[0][2];



                b = sqrt(gxblue * gxblue + gyblue * gyblue);
                r = sqrt(gxred * gxred + gyred * gyred);
                g = sqrt(gxgreen * gxgreen + gygreen * gygreen);


                if (b > 255.0)
                {
                    image[i][j].rgbtBlue = 255;
                }
                else
                {
                    image[i][j].rgbtBlue = round(b);
                }

                if (r > 255.0)
                {
                    image[i][j].rgbtRed = 255;
                }
                else
                {
                    image[i][j].rgbtRed = round(r);
                }

                if (g > 255.0)
                {
                    image[i][j].rgbtGreen = 255;
                }
                else
                {
                    image[i][j].rgbtGreen = round(g);
                }
            }
        }
    }*/
    return;
}
