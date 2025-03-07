#include <iostream>
using namespace std;
struct Image
{
    int *pixels;
    int width;
    int height;
};
void printImage(const Image &img)
{
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            cout << img.pixels[i * img.width + j] << " ";
        }
        cout << endl;
    }
}
Image halve(const Image &img)
{
    int newWidth = (img.width + 1) / 2;
    int newHeight = (img.height + 1) / 2;
    int *newPixels = new int[newWidth * newHeight];
    int index = 0;

    for (int i = 0; i < img.height; i += 2)
    {
        for (int j = 0; j < img.width; j += 2)
        {
            newPixels[index++] = img.pixels[i * img.width + j];
        }
    }

    Image newImg = {newPixels, newWidth, newHeight};
    return newImg;
}
int main()
{
    int pixels[] = {
        1, 3, 0, 5, 2,
        4, 1, 8, 3, 1,
        3, 3, 1, 3, 2};
    Image img = {pixels, 5, 3};
    printImage(img);
    printImage(halve(img));
}