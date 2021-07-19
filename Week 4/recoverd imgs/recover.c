#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // to check if 2 arguments are there
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //Open MEmory card
    FILE *file, *img;
    file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }


    typedef uint8_t BYTE;
    BYTE bytes[512];
    int count = 0, i = 0;
    printf("cod26 correct");

    while (fread(bytes, 512, 1, file) == 1)
    {
        printf("cod30 correct");
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            char buffer[8];
            sprintf(buffer, "%03i.jpg", count);
            count++;
            i++;
            if (count == 1)
            {
                img = fopen(buffer, "w");

                fwrite(bytes, 512, 1, img);

            }
            else
            {
                fclose(img);
                img = fopen(buffer, "w");

                fwrite(bytes, 512, 1, img);

            }
        }
        else
        {
            if (count == i && count > 0)
            {
                fwrite(bytes, 512, 1, img);
            }


        }

    }
    fclose(img);
    fclose(file);
    return 0;

}