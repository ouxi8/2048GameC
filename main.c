#include <stdio.h>
#include <ctype.h> // for tolower()
#include "logic.h"

#define NROWS 4
#define NCOLS 4

int main() {
    int matrix[NROWS * NCOLS];
    initGame(matrix);

    game_state_t state = GAME_NOT_OVER;
    char input;

    printf("Welcome to 2048! Use W (up), S (down), A (left), D (right) to move.\n\n");

    while (state == GAME_NOT_OVER) {
        printMatrix(matrix);

        // Prompt for input
        printf("Enter move (W/A/S/D): ");
        scanf(" %c", &input);
        input = tolower(input); // Normalize to lowercase

        // Determine the direction based on user input
        game_direction_t action;
        switch (input) {
            case 'w':
                action = UP;
                break;
            case 's':
                action = DOWN;
                break;
            case 'a':
                action = LEFT;
                break;
            case 'd':
                action = RIGHT;
                break;
            default:
                printf("Invalid input! Please use W, A, S, or D.\n");
                continue; // Prompt for input again if invalid
        }

        // Execute the move
        move(matrix, action);

        // Check game state after the move
        state = getCurrentState(matrix);

        if (state == WIN) {
            printMatrix(matrix);
            printf("Congratulations, you've reached 2048! You win!\n");
            break;
        } else if (state == GAME_OVER) {
            printMatrix(matrix);
            printf("Game Over! No more moves possible.\n");
            break;
        }
    }

    return 0;
}
