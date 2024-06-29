#include "helpers.h"
#include <math.h>

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Filter using sepia equation
    int red, blue, green;
    for (int i = 0; i < height; i++)
    {
        for (int h = 0; h < width; h++)
        {
            red = round(.393 * image[i][h].rgbtRed + .769 * image[i][h].rgbtGreen  + .189 * image[i][h].rgbtBlue);
            green = round(.349 * image[i][h].rgbtRed + .686 * image[i][h].rgbtGreen + .168 * image[i][h].rgbtBlue);
            blue = round(.272 * image[i][h].rgbtRed + .534 * image[i][h].rgbtGreen + .131 * image[i][h].rgbtBlue);
            if (red > 255) red = 255;
            if (green > 255) green = 255;
            if (blue > 255) blue = 255;
            image[i][h].rgbtRed = red;
            image[i][h].rgbtGreen = green;
            image[i][h].rgbtBlue = blue;
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
