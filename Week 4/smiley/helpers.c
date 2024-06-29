#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    //Iterate through height
    for (int i = 0; i < height; i++)
    {
        // Iterate through width
        for (int d = 0; d < width; d++)
        {
            // If color is black change it to neon green
            if (image[i][d].rgbtBlue == 0x00 && image[i][d].rgbtGreen == 0x00 && image[i][d].rgbtRed == 0x00)
            {
                image[i][d].rgbtRed = 0x39;
                image[i][d].rgbtGreen = 0xFF;
                image[i][d].rgbtBlue = 0x14;
            }
        }
    }
}
