#include <iostream>
using namespace std;
int** transpose(int** matrix, int nRows, int nCols)
{
    int **transpose = new int*[nCols];
    for(int i = 0; i < nCols; i++)
    {
        transpose[i] = new int[nRows];
    }
    for(int i = 0; i < nCols; i++)
    {
        for(int j = 0; j < nRows;j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}
int main()
{
    int nRows, nCols;
    int ** matrix = new int*[nRows];
    for(int i = 0; i < nRows; i++)
    {
        matrix[i] = new int [nCols];
    }
    int ** transposes = transpose(matrix, nRows,nCols);
}