//
// Created by Oux on 06/11/2024.
//

#ifndef LOGIC_H
#define LOGIC_H

// Grid dimensions
#define NROWS 4
#define NCOLS 4

/**
 Score of the game
 */
extern int score;

// Game state enumeration to represent game outcomes
typedef enum { WIN, GAME_OVER, GAME_NOT_OVER } game_state_t;

// Direction enumeration for player moves
typedef enum { UP, DOWN, LEFT, RIGHT } game_actions_t;

// Initializes the game grid
void initGame(int matrix[]);

// Returns the current game state (WIN, GAME_NOT_OVER, or GAME_OVER)
game_state_t checkWin(const int matrix[]);

// Prints the game grid to the console
void printMatrix(const int matrix[]);

// Applies a move in the specified direction (UP, DOWN, LEFT, or RIGHT)
void move(int matrix[], const game_actions_t action);

int getScore();

#endif // LOGIC_H
