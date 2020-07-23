# TIC TAC TOE IN PYTHON

GameBoard = {'1': ' ', '2': ' ', '3': ' ',
             '4': ' ', '5': ' ', '6': ' ',
             '7': ' ', '8': ' ', '9': ' '}
''' 
Dictionary created to represent the Game Board
'''
boardkeys = []

for key in GameBoard:
    boardkeys.append(key)

# This is going to print the updated board after every move


def PrintBoard(board):
    print(board['1'] + '|' + board['2'] + '|' + board['3'])
    print('-+-+-')
    print(board['4'] + '|' + board['5'] + '|' + board['6'])
    print('-+-+-')
    print(board['7'] + '|' + board['8'] + '|' + board['9'])


def Game():
    turn = 'X'
    count = 0
    
    for i in range(10):
        PrintBoard(GameBoard)
        print("It's your turn " + turn +". Add enter the box number where you want to add")

        move = input()

        if GameBoard[move] == ' ':
            GameBoard[move] = turn
            count+=1
        else:
            print('Place occupied.\n Try Again')
            continue