#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Averages the color values of the image and makes the images new colour
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            avg = round((image[i][h].rgbtBlue + image[i][h].rgbtGreen + image[i][h].rgbtRed) / 3.0);
            image[i][h].rgbtRed = image[i][h].rgbtBlue = image[i][h].rgbtGreen = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Flip the image horizontally by swapping the values till the middle of the width for every height
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width / 2; h++)
        {
            temp = image[i][h];
            image[i][h] = image[i][width - (h + 1)];
            image[i][width - (h + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // save the colors of the image in an new array and change find the average of every pixel neighboring
    RGBTRIPLE temp[height][width];
    float count;
    int red, green, blue;
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            count = 0, red = 0, green = 0, blue = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if(i + c < 0 || c + i > (height - 1) || a + h < 0 || a + h > (width - 1)) continue;
                    red += image[i + c][h + a].rgbtRed;
                    green += image[i + c][h + a].rgbtGreen;
                    blue += image[i + c][h + a].rgbtBlue;
                    count++;
                }
            }
            temp[i][h].rgbtRed = round(red / count);
            temp[i][h].rgbtGreen = round(green / count);
            temp[i][h].rgbtBlue = round(blue / count);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++) image[i][h] = temp[i][h];
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int rgx, rgy, bgx, bgy, ggx, ggy, red, green, blue;
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            rgx = 0, rgy = 0, bgx = 0, bgy = 0, ggx = 0, ggy = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if(i + c < 0 || c + i > (height - 1) || a + h < 0 || a + h > (width - 1)) continue;
                    bgx += image[i + c][h + a].rgbtBlue * gx[c + 1][a + 1];
                    bgy += image[i + c][h + a].rgbtBlue * gy[c + 1][a + 1];
                    ggx += image[i + c][h + a].rgbtGreen * gx[c + 1][a + 1];
                    ggy += image[i + c][h + a].rgbtGreen * gy[c + 1][a + 1];
                    rgx += image[i + c][h + a].rgbtRed * gx[c + 1][a + 1];
                    rgy += image[i + c][h + a].rgbtRed * gy[c + 1][a + 1];
                }
            }
            red = (rgx * rgx) + (rgy * rgy);
            green = (ggx * ggx) + (ggy * ggy);
            blue = (bgx * bgx) + (bgy * bgy);
            red = round(sqrt(red));
            green = round(sqrt(green));
            blue = round(sqrt(blue));
            if (red > 255) red = 255;
            if (green > 255) green = 255;
            if (blue > 255) blue = 255;
            temp[i][h].rgbtRed = red;
            temp[i][h].rgbtGreen = green;
            temp[i][h].rgbtBlue = blue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++) image[i][h] = temp[i][h];
    }
    return;
}
