//
// Created by Oux on 06/11/2024.
//

#ifndef UTILS_H
#define UTILS_H

// Swaps two integer values
void swap(int *a, int *b);

// Reverses rows in the game grid (for movement operations)
void reverseMatrix(int matrix[], int nrows, int ncols);

// Transposes the matrix (for movement operations)
void transposeMatrix(int matrix[], int nrows, int ncols);

#endif //UTILS_H
