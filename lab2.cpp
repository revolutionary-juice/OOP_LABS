#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

const int M = 5, N = 2;

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(" %-2d ", matrix[i][j]);
        }
        std::cout << '\n';
    }
    std::cout << std::string(cols * 4, '-') << '\n';
}

void createMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    srand(time(0));

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
    }

    createMatrix(matrix, M, N);
    printMatrix(matrix, M, N);

    
    for (int i = 0; i < M - 1; i++) {
        int maxIndex = i;
        int maxAbsValue = std::abs(matrix[i][i]);

        for (int j = i + 1; j < M; j++) {
            if (std::abs(matrix[j][j]) > maxAbsValue) {
                maxAbsValue = std::abs(matrix[j][j]);
                maxIndex = j;
            }
        }

        
        std::swap(matrix[i], matrix[maxIndex]);
    }

    printMatrix(matrix, M, N);

   
    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
