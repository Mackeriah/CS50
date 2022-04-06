#include "helpers.h"
#include "stdio.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int colourAverage = round( ( (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) /3 );
            image[i][j].rgbtBlue = colourAverage;
            image[i][j].rgbtGreen = colourAverage;
            image[i][j].rgbtRed = colourAverage;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // sepia calculation
            int sepiaBlue = round( (float).272 * image[i][j].rgbtRed + (float).534 * image[i][j].rgbtGreen + (float).131 * image[i][j].rgbtBlue);
            int sepiaGreen = round( (float).349 * image[i][j].rgbtRed + (float).686 * image[i][j].rgbtGreen + (float).168 * image[i][j].rgbtBlue);
            int sepiaRed = round( (float).393 * image[i][j].rgbtRed + (float).769 * image[i][j].rgbtGreen + (float).189 * image[i][j].rgbtBlue);

            // convert float to int
            int newBlue = sepiaBlue;
            int newGreen = sepiaGreen;
            int newRed = sepiaRed;

            // cap at 255 if required
            if (newBlue > 255)
            {
                newBlue = 255;
            }
            if (newGreen > 255)
            {
                newGreen = 255;
            }
            if (newRed > 255)
            {
                newRed = 255;
            }

            image[i][j].rgbtBlue = newBlue;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtRed = newRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create new array to store the mirrored image current row
    RGBTRIPLE mirrorImage[height][width];

    for (int i = 0; i < height; i++)
    {
        // store data in mirror  array
        for (int j = 0; j < width; j++)
        {
            mirrorImage[i][width-j-1] = image[i][j];
        }

        // set image array to mirror array
        for (int k = 0; k < width; k++)
        {
            image[i][k] = mirrorImage[i][k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // for (int i = 0; i < height; i++)
    // {
    //     // store data in mirror  array
    //     for (int j = 0; j < width; j++)
    //     {

    //     }
    // }

    // average = numbers added together divided by total number of numbers
    // e.g. av of 3,5,7 = (3+5+7) /3

    /*
    int currentRowBlueBlur = cell[i][j].rgbtBlue + cell[i][j-1].rgbtBlue + cell[i][j+1].rgbtBlue;

    // check that a row exists before current row
    if i != 0
    {
        previousRowBlueBlur = cell[i-1][j-3].rgbtBlue + cell[i-1][j-4].rgbtBlue + cell[i-1][j-5].rgbtBlue;
        currentRowBlueBlur = currentRowBlueBlur + previousRowBlueBlur;
    }

    // check that a row exists after current row
    if i != height-1
    {
        nextRowBlueBlur = cell[i+1][j+3].rgbtBlue + cell[i+1][j+5].rgbtBlue + cell[i+1][j+5].rgbtBlue;
        currentRowBlueBlur = currentRowBlueBlur + nextRowBlueBlur;
    }
    */


    // int boxBlurBlue = image[i][j].rgbtBlue
    // int boxBlurGreen = image[i][j].rgbtGreen
    // int boxBlurRed = image[i][j].rgbtRed

    return;
}
