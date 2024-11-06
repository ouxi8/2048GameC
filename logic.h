//
// Created by Oux on 06/11/2024.
//

#ifndef LOGIC_H
#define LOGIC_H

// Grid dimensions
#define NROWS 4
#define NCOLS 4

// Game state enumeration to represent game outcomes
typedef enum { WIN, GAME_OVER, GAME_NOT_OVER } game_state_t;

// Direction enumeration for player moves
typedef enum { UP, DOWN, LEFT, RIGHT } game_direction_t;

// Swaps two integer values
void swap(int *a, int *b);

// Initializes the game grid
void initGame(int matrix[]);

// Returns the current game state (WIN, GAME_NOT_OVER, or GAME_OVER)
game_state_t getCurrentState(int matrix[]);

// Prints the game grid to the console
void printMatrix(int matrix[]);

// Adds a new value (2 or 4) in a random empty position
void addValue(int matrix[]);

// Reverses rows in the game grid (for movement operations)
void reverseMatrix(int matrix[]);

// Transposes the matrix (for movement operations)
void transposeMatrix(int matrix[]);

// Merges adjacent cells in the grid (based on game rules)
void merge(int matrix[]);

// Applies a move in the specified direction (UP, DOWN, LEFT, or RIGHT)
void move(int matrix[], const game_direction_t action);

#endif // LOGIC_H
