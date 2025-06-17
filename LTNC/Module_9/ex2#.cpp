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
    int newWidth = (img.width % 2 == 0) ? img.width / 2 : 1 + img.width / 2;
    int newHeight = (img.height % 2 == 0) ? img.height / 2 : 1 + img.height / 2;

    Image result;
    result.width = newWidth;
    result.height = newHeight;
    result.pixels = new int[newWidth * newHeight];

    for (int i = 0; i < newHeight; ++i)
    {
        for (int j = 0; j < newWidth; ++j)
        {
            result.pixels[i * newWidth + j] = img.pixels[(2 * i) * img.width + (2 * j)];
        }
    }

    return result;
}

int main()
{
    int pixels[] = {1, 3, 0, 5, 2, 4, 1, 8, 3, 1, 3, 3, 1, 3, 2};
    Image img = {pixels, 5, 3};
    printImage(img);
    printImage(halve(img));
}