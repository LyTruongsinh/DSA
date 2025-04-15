#include <iostream>
using namespace std;

int** inputMatrix(int nRows, int nCols) {
    int** matrix = new int*[nRows];
    for (int i = 0; i < nRows; i++) {
        matrix[i] = new int[nCols];
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int nRows, int nCols) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** transpose(int** matrix, int nRows, int nCols) {
    int** transposedMatrix = new int*[nCols];
    for (int i = 0; i < nCols; i++) {
        transposedMatrix[i] = new int[nRows];
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

int main() {
    int nRows, nCols;
    cout << "Nhập số hàng và số cột: ";
    cin >> nRows >> nCols;

    cout << "Nhập ma trận:\n";
    int** matrix = inputMatrix(nRows, nCols);

    cout << "Ma trận gốc:\n";
    printMatrix(matrix, nRows, nCols);

    int** transposed = transpose(matrix, nRows, nCols);
    cout << "Ma trận chuyển vị:\n";
    printMatrix(transposed, nCols, nRows);

    // Giải phóng bộ nhớ
    for (int i = 0; i < nRows; i++) delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < nCols; i++) delete[] transposed[i];
    delete[] transposed;

    return 0;
}
