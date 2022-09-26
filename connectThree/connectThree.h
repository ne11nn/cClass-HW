#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define ROW 3
#define COL 3
#define PLAYER_WIN 1
#define COMPUTER_WIN 2
#define TIE 0

void menu();
void game();
void initBoard(char board[ROW][COL], int row, int col);
void displayBoard(char board[ROW][COL], int row, int col);
/*
draw: 0
player win: 1
comp win: 2
continue: 3
*/