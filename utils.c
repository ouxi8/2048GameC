//
// Created by Oux on 06/11/2024.
//

#include "utils.h"

// Swaps two integers
void swap(int *a, int *b) {
    const int aux = *a;
    *a = *b;
    *b = aux;
}

// Reverses each row of the matrix
void reverseMatrix(int matrix[], int nrows, int ncols) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols / 2; j++) {
            swap(&matrix[i * ncols + j], &matrix[i * ncols + (ncols - 1 - j)]);
        }
    }
}

// Transposes the matrix in-place
void transposeMatrix(int matrix[], int nrows, int ncols) {
    for (int i = 0; i < nrows; i++) {
        for (int j = i + 1; j < ncols; j++) {
            swap(&matrix[i * ncols + j], &matrix[j * ncols + i]);
        }
    }
}
