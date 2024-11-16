//
// Created by Oux on 06/11/2024.
//

#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

#define NROWS 4
#define NCOLS 4
#define PERCENTAGE_FOR_4 20

//----------------------------------------------------------------//
static void addValue(int matrix[]);

// Helper function to move and merge a row to the left
static void shiftLeft(int row[]);

static void mergeLeft(int row[]);

// Core move function for each row to the left
static void moveRowLeft(int row[]);

//----------------------------------------------------------------//

int score = 0;

void initGame(int matrix[]) {
    srand(time(NULL));
    for (int i = 0; i < NROWS * NCOLS; i++) {
        matrix[i] = 0;
    }
    addValue(matrix);
    addValue(matrix); // Start game with two cells filled
}

game_state_t checkWin(const int matrix[]) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            int currentIndex = i * NCOLS + j;
            if (matrix[currentIndex] == 2048) return WIN;
            if (matrix[currentIndex] == 0) return GAME_NOT_OVER;
            if (j < NCOLS - 1 && matrix[currentIndex] == matrix[currentIndex + 1]) return GAME_NOT_OVER;
            if (i < NROWS - 1 && matrix[currentIndex] == matrix[currentIndex + NCOLS]) return GAME_NOT_OVER;
        }
    }
    return GAME_OVER;
}

void printMatrix(const int matrix[]) {
    printf("\n-------------------------\n"); // Top border

    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            if (matrix[i * NCOLS + j] == 0) {
                printf("|     "); // Empty cell
            } else {
                printf("| %4d ", matrix[i * NCOLS + j]); // Filled cell
            }
        }
        printf("|\n");
        printf("-------------------------\n"); // Row separator
    }
    printf("\n");
}


void move(int matrix[], const game_actions_t action) {
    switch (action) {
        case LEFT:
            for (int i = 0; i < NROWS; i++) {
                moveRowLeft(&matrix[i * NCOLS]);
            }
            break;
        case RIGHT:
            reverseMatrix(matrix, NCOLS, NCOLS);
            for (int i = 0; i < NROWS; i++) {
                moveRowLeft(&matrix[i * NCOLS]);
            }
            reverseMatrix(matrix, NCOLS, NCOLS);
            break;
        case UP:
            transposeMatrix(matrix, NCOLS, NCOLS);
            for (int i = 0; i < NCOLS; i++) {
                moveRowLeft(&matrix[i * NCOLS]);
            }
            transposeMatrix(matrix, NCOLS, NCOLS);
            break;
        case DOWN:
            transposeMatrix(matrix, NCOLS, NCOLS);
            reverseMatrix(matrix, NCOLS, NCOLS);
            for (int i = 0; i < NCOLS; i++) {
                moveRowLeft(&matrix[i * NCOLS]);
            }
            reverseMatrix(matrix, NCOLS, NCOLS);
            transposeMatrix(matrix, NCOLS, NCOLS);
            break;
    }
    addValue(matrix);
}

int getScore() {
    return score;
}

//----------------------------------------------------------------//
static void addValue(int matrix[]) {
    int emptyCells[NROWS * NCOLS];
    int emptyCount = 0;

    for (int i = 0; i < NROWS * NCOLS; i++) {
        if (matrix[i] == 0) {
            emptyCells[emptyCount++] = i;
        }
    }

    if (emptyCount > 0) {
        const int chosenIndex = emptyCells[rand() % emptyCount];
        matrix[chosenIndex] = (rand() % PERCENTAGE_FOR_4 == 0) ? 4 : 2; // PERCENTAGE_FOR_4% chance to add a 4
    }
}

// Helper function to move and merge a row to the left
static void shiftLeft(int row[]) {
    int insertPos = 0;
    for (int j = 0; j < NCOLS; j++) {
        if (row[j] != 0) {
            row[insertPos++] = row[j];
        }
    }
    for (int j = insertPos; j < NCOLS; j++) {
        row[j] = 0;
    }
}

static void mergeLeft(int row[]) {
    for (int j = 0; j < NCOLS - 1; j++) {
        if (row[j] != 0 && row[j] == row[j + 1]) {
            row[j] *= 2;
            row[j + 1] = 0;
        }
    }
}

// Core move function for each row to the left
static void moveRowLeft(int row[]) {
    shiftLeft(row);
    mergeLeft(row);
    shiftLeft(row);
}
