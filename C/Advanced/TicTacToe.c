#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "gamefunction.h"

int main()
{
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // 3x3 grid with numbers 1-9
    char goption;
    printf("press 'p' to print the tictactoe board\n");                           //only prints board
    printf("press 'c' to create a tictactoe board with X and O cells\n");         //creates board user can input
    printf("press 't' to test if a tictactoe board is valid or invalid board\n"); // only gives board validity
    printf("press 'w' to predict the winning cell for player X or O\n");          // only gives hints to the user
    printf("press 'g' to play the full game\n");                                  // full game with all features and users can determine winners
    printf("press 'e' to exit\n");
    scanf("%c", &goption);
    switch (goption)
    {
    case 'p':
        PrintBoard(3, 3, board);
        break;
    case 'c':
        for (int i = 0; i < 9; i++)
            CreateBoard(3, 3, board);
        break;
    case 't':
        for (int i = 0; i < 9; i++)
        {
            CreateBoard(3, 3, board); //generates game board for IsValidBoard()
            IsValidBoard(3, 3, board);
        }
        break;
    case 'w':
        for (int i = 0; i < 9; i++)
        {
            CreateBoard(3, 3, board); //generates game board for ListWinningCells()
            ListWinningCells(3, 3, board);
        }
        break;
    case 'g':
        PlayGame(3, 3, board);
        break;
    case 'e':
        exit(0);
        break;
    default:
        printf("Try again!");
        break;
    }
}
