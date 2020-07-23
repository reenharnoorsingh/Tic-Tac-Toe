# Tic Tac Toe in Pyhton

# Dictionary Created to represent Game Board

GameBoard = {'1': ' ', '2': ' ', '3': ' ',
             '4': ' ', '5': ' ', '6': ' ',
             '7': ' ', '8': ' ', '9': ' '}

boardkeys = []

for key in GameBoard:
    boardkeys.append(key)

# Print board function prints the game board and constantly updates it 


def PrintBoard(board):
    print(board['1'] + '|' + board['2'] + '|' + board['3'])
    print('-+-+-')
    print(board['4'] + '|' + board['5'] + '|' + board['6'])
    print('-+-+-')
    print(board['7'] + '|' + board['8'] + '|' + board['9'])

# main function


def Game():

    turn = 'X'
    count = 0

    for i in range(10):
        PrintBoard(GameBoard)
        print("It's your turn," + turn + ".Move to which place?")

        move = input()

        if GameBoard[move] == ' ':
            GameBoard[move] = turn
            count += 1
        else:
            print("That place is already filled.\nTry Again")
            continue

        #Winning possibilities
        if count >= 5:
            if GameBoard['7'] == GameBoard['8'] == GameBoard['9'] != ' ':  # across the bottom
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['4'] == GameBoard['5'] == GameBoard['6'] != ' ':  # across the middle
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['1'] == GameBoard['2'] == GameBoard['3'] != ' ':  # across the top
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['1'] == GameBoard['4'] == GameBoard['7'] != ' ':  # down the left side
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['2'] == GameBoard['5'] == GameBoard['8'] != ' ':  # down the middle
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['3'] == GameBoard['6'] == GameBoard['9'] != ' ':  # down the right side
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['7'] == GameBoard['5'] == GameBoard['3'] != ' ':  # diagonal
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break
            elif GameBoard['1'] == GameBoard['5'] == GameBoard['9'] != ' ':  # diagonal
                PrintBoard(GameBoard)
                print("\nGame Over.\n")
                print(" **** " + turn + " won. ****")
                break

        # If neither X nor O wins and the board is full, we'll declare the result as 'tie'.
        if count == 9:
            print("\nGame Over.\n")
            print("It's a Tie!!")

        # Changes the player after every move.
        if turn == 'X':
            turn = 'O'
        else:
            turn = 'X'

    # Ask if player wants to restart the game or not.
    restart = input("Do want to play Again?(y/n)")
    if restart == "y" or restart == "Y":
        for key in boardkeys:
            GameBoard[key] = " "

        Game()


if __name__ == "__main__":
    Game()
