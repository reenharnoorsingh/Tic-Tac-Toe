#include <iostream>
using namespace std;

char Board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; //declaring the board
int WinnerCheck();                                                   // Verifies all the winning cases
void GameBoard();                                                    //function to generate game board

int main()
{
    int player = 1, i, choice; //declaring variables

    char mark;
    do
    {
        GameBoard();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  "; //gives the player choice to enter value inside the board
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && Board[1] == '1')// adding the selection into the Game Board

            Board[1] = mark;
        else if (choice == 2 && Board[2] == '2')

            Board[2] = mark;
        else if (choice == 3 && Board[3] == '3')

            Board[3] = mark;
        else if (choice == 4 && Board[4] == '4')

            Board[4] = mark;
        else if (choice == 5 && Board[5] == '5')

            Board[5] = mark;
        else if (choice == 6 && Board[6] == '6')

            Board[6] = mark;
        else if (choice == 7 && Board[7] == '7')

            Board[7] = mark;
        else if (choice == 8 && Board[8] == '8')

            Board[8] = mark;
        else if (choice == 9 && Board[9] == '9')

            Board[9] = mark;
        else
        {
            cout << "Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i = WinnerCheck();

        player++;
    } while (i == -1);//end of inner loop
    GameBoard();
    if (i == 1)

        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";

    cin.ignore(); // used to ignore or clear one or more characters from the input buffer
    cin.get();    //accesses character array
    return 0;
}

int WinnerCheck() // all the winning cases
{
    if (Board[1] == Board[2] && Board[2] == Board[3])

        return 1;
    else if (Board[4] == Board[5] && Board[5] == Board[6])

        return 1;
    else if (Board[7] == Board[8] && Board[8] == Board[9])

        return 1;
    else if (Board[1] == Board[4] && Board[4] == Board[7])

        return 1;
    else if (Board[2] == Board[5] && Board[5] == Board[8])

        return 1;
    else if (Board[3] == Board[6] && Board[6] == Board[9])

        return 1;
    else if (Board[1] == Board[5] && Board[5] == Board[9])

        return 1;
    else if (Board[3] == Board[5] && Board[5] == Board[7])

        return 1;
    else if (Board[1] != '1' && Board[2] != '2' && Board[3] != '3' && Board[4] != '4' && Board[5] != '5' && Board[6] != '6' && Board[7] != '7' && Board[8] != '8' && Board[9] != '9')

        return 0;
    else
        return -1;
}

void GameBoard()//Generate and Prints the Game Board
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << Board[1] << "  |  " << Board[2] << "  |  " << Board[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << Board[4] << "  |  " << Board[5] << "  |  " << Board[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << Board[7] << "  |  " << Board[8] << "  |  " << Board[9] << endl;

    cout << "     |     |     " << endl
         << endl;
}
