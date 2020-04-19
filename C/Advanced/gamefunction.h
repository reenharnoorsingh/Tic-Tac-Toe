#ifndef ASSIGNS_GAMEFUNCTION_H
#define ASSIGNS_GAMEFUNCTION_H

void InitializeBoard(int , int , char ** []);

void PrintBoard(int ,int , char ** []);

void CreateBoard(int ,int ,char ** []);

int IsValidBoard(int ,int ,char ** []);

void ListWinningCells(int ,int ,char ** []);

char WhoIsTheWinner(int ,int ,char ** []);

int PlayGame(int ,int ,char ** []);

#endif