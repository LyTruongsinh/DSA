#include <iostream>
using namespace std;
int **inputMatrix(int nRows, int nCols)
{
    int **matrix = new int *[nRows];
    for (int i = 0; i < nRows; i++)
    {
        matrix[i] = new int[nCols];
    }
    for (int i = 0; i <= nRows; i++)
    {
        for (int j = 0; j <= nCols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
void printMatrix(int **matrix, int nRows, int nCols)
{
    for (int i = 0; i <= nRows; i++)
    {
        for (int j = 0; j <= nCols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int **matrix = inputMatrix(n, m);
    printMatrix(matrix, n, m);
}