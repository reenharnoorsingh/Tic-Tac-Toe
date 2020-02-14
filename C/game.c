#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void InitializeBoard(int m, int n, char board[][n]) // initializes the game board
{
    int c = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = c + '0';
            c++;
        }
    }
}
void PrintBoard(int m, int n, char board[][n]) // prints the grid
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != n - 1)
            {
                printf(" %c |", board[i][j]);
            }
            else
            {
                printf(" %c ", board[i][j]);
            }
        }
        if (i != m - 1)
        {
            printf("\n---|---|---\n"); // style of our grid
            /*
              The grid will look like this:
              1  2  3
              4  5  6
              7  8  9
            */
        }
    }
    printf("\n");
}
void CreateBoard(int m, int n, char board[][n]) // Fills in the numbers within grids and asks for the user input
{
    int cell; // inputs number 1-9
    char c;   // inputs either X or O
    printf("Enter the number of the cell where you want to insert X or O: ");
    while (1)
    {

        scanf("%d", &cell);
        if (cell < 1 || cell > 9)
        {
            printf("\nEnter valid number between 1-9: ");
        }
        else
            break;
    }
    printf("\nEnter X or O to put in board: ");
    while (1)
    {
        char ch[2];
        scanf("%s", ch);
        c = ch[0];
        board[(cell - 1) / 3][(cell - 1) % 3] = c;
        if (c != 'X' && c != 'O')
        {
            printf("\nEnter valid character X or O : ");
        }
        else
            break;
    }
    PrintBoard(m, n, board); // prints the updated board
}
int IsValidBoard(int m, int n, char board[][n]) // checks the validity of the inputs
{
    int x = 0; //counts X
    int o = 0; // counts O
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'X')
                x += 1;
            if (board[i][j] == 'O')
                o += 1;
        }
    }
    if (x - o == -1 || x - o == 1 || x - o == 0)
        printf("The board is valid\n");
    else
    {
        printf("The board is invalid\n");
        printf("Start the game again!");
        exit(0); //exits the game since there is an Invalid board
    }
}
void ListWinningCells(int m, int n, char board[m][n]) // gives hints to users about where to input to win
{
    if ((board[0][0] == board[0][1]) && board[0][2] == '3')
        printf("\nif you put %c in cell 3 Player %c wins\n", board[0][0], board[0][0]);
    if ((board[0][0] == board[1][0]) && board[2][0] == '7')
        printf("\nif you put %c in cell 7 Player %c wins\n", board[0][0], board[0][0]);
    if ((board[0][0] == board[1][1]) && board[2][2] == '9')
        printf("\nif you put %c in cell 9 Player %c wins\n", board[0][0], board[0][0]);
    if ((board[0][1] == board[1][1]) && board[2][1] == '8')
        printf("\nif you put %c in cell 8 Player %c wins\n", board[0][1], board[0][1]);
    if ((board[0][1] == board[0][2]) && board[0][0] == '1')
        printf("\nif you put %c in cell 1 Player %c wins\n", board[0][1], board[0][1]);
    if ((board[0][2] == board[1][2]) && board[2][2] == '9')
        printf("\nif you put %c in cell 9 Player %c wins\n", board[0][2], board[0][2]);
    if ((board[0][2] == board[1][1]) && board[2][0] == '7')
        printf("\nif you put %c in cell 7 Player %c wins\n", board[0][2], board[0][2]);
    if ((board[1][0] == board[1][1]) && board[1][2] == '6')
        printf("\nif you put %c in cell 6 Player %c wins\n", board[1][0], board[1][0]);
    if ((board[1][0] == board[2][0]) && board[0][0] == '1')
        printf("\nif you put %c in cell 1 Player %c wins\n", board[1][0], board[1][0]);
    if ((board[1][1] == board[1][2]) && board[1][0] == '4')
        printf("\nif you put %c in cell 4 Player %c wins\n", board[1][1], board[1][1]);
    if ((board[1][1] == board[2][0]) && board[0][2] == '3')
        printf("\nif you put %c in cell 3 Player %c wins\n", board[1][1], board[1][1]);
    if ((board[1][1] == board[2][1]) && board[0][1] == '2')
        printf("\nif you put %c in cell 2 Player %c wins\n", board[1][1], board[1][1]);
    if ((board[1][1] == board[2][2]) && board[0][0] == '1')
        printf("\nif you put %c in cell 1 Player %c wins\n", board[1][1], board[1][1]);
    if ((board[2][0] == board[2][1]) && board[2][2] == '9')
        printf("\nif you put %c in cell 9 Player %c wins\n", board[2][0], board[2][0]);
    if ((board[2][1] == board[2][2]) && board[2][0] == '7')
        printf("\nif you put %c in cell 7 Player %c wins\n", board[2][1], board[2][1]);
    if ((board[0][1] == board[2][1]) && board[1][1] == '5')
        printf("\nif you put %c in cell 5 Player %c wins\n", board[0][1], board[0][1]);
    if ((board[0][0] == board[2][0]) && board[1][0] == '4')
        printf("\nif you put %c in cell 4 Player %c wins\n", board[0][0], board[0][0]);
    if ((board[0][2] == board[2][2]) && board[1][2] == '6')
        printf("\nif you put %c in cell 6 Player %c wins\n", board[0][2], board[0][2]);
    if ((board[2][2] == board[1][2]) && board[0][2] == '3')
        printf("\nif you put %c in cell 3 Player %c wins\n", board[2][2], board[2][2]);
    if ((board[0][0] == board[0][2]) && board[0][1] == '2')
        printf("\nif you put %c in cell 2 Player %c wins\n", board[0][0], board[0][0]);
    if ((board[1][1] == board[1][2]) && board[1][1] == '5')
        printf("\nif you put %c in cell 5 Player %c wins\n", board[1][1], board[1][1]);
    if ((board[2][0] == board[2][2]) && board[2][1] == '8')
        printf("\nif you put %c in cell 8 Player %c wins\n", board[2][0], board[2][0]);
    if ((board[0][2] == board[2][0]) && board[1][1] == '5')
        printf("\nif you put %c in cell 5 Player %c wins\n", board[0][2], board[0][2]);
    if ((board[0][0] == board[2][2]) && board[1][1] == '5')
        printf("\nif you put %c in cell 5 Player %c wins\n", board[0][0], board[0][0]);
}
char WhoIsTheWinner(int m, int n, char board[][n]) //checks the inputs and if they match in a line, declares winner
{
    if ((board[0][0] == board[0][1]) && board[0][0] == board[0][2])
    {
        printf("Player %c is the winner", board[0][0]);
        exit(0);
    }
    else if ((board[2][0] == board[2][1]) && board[2][0] == board[2][2])
    {
        printf("Player %c is the winner", board[2][0]);
        exit(0);
    }
    else if ((board[0][0] == board[1][0]) && board[0][0] == board[2][0])
    {
        printf("Player %c is the winner", board[0][0]);
        exit(0);
    }
    else if ((board[0][2] == board[1][2]) && board[0][2] == board[2][2])
    {
        printf("Player %c is the winner", board[0][2]);
        exit(0);
    }
    else if ((board[0][0] == board[1][1]) && board[0][0] == board[2][2])
    {
        printf("Player %c is the winner", board[0][0]);
        exit(0);
    }
    else if ((board[0][2] == board[1][1]) && board[0][2] == board[2][0])
    {
        printf("Player %c is the winner", board[0][2]);
        exit(0);
    }
    else if ((board[1][0] == board[1][1]) && board[1][0] == board[1][2])
    {
        printf("Player %c is the winner", board[1][0]);
        exit(0);
    }
    else if ((board[0][1] == board[1][1]) && board[0][1] == board[2][1])
    {
        printf("Player %c is the winner", board[0][1]);
        exit(0);
    }
}
int PlayGame(int m, int n, char board[][n])
{

    printf("Welcome!\n");
    printf("GameBoard!!\n");
    InitializeBoard(3, 3, board);
    PrintBoard(3, 3, board);
    for (int i = 0; i < 9; i++) //loop needed to run the program to provide chances for the players
    {
        CreateBoard(3, 3, board);
        IsValidBoard(3, 3, board);
        ListWinningCells(3, 3, board);
        WhoIsTheWinner(3, 3, board);
    }
}
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
