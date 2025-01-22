
#include <iostream>
#include <cstdlib> // Для rand()
using namespace std;

const int SIZE = 3; // Фіксований розмір матриці

void initMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            matrix[i][j] = rand() % 100;
}

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void findMinMax(int matrix[SIZE][SIZE], int& min, int& max) {
    min = max = matrix[0][0];
    for (int i = 0; i < SIZE; ++i) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

int main() {
    int matrix[SIZE][SIZE];
    int min, max;

    initMatrix(matrix);
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    findMinMax(matrix, min, max);
    cout << "Min on diagonal: " << min << ", Max on diagonal: " << max << endl;

    return 0;
}
