#include <stdio.h>
#include <windows.h>

#define EMPTY 0
#define WALL 1
#define APPLE 2
#define SNAKEHEAD 3
#define SNAKEBODY 4
#define ROW 23
#define COL 42

void color (int c);
void CursorJump (int x, int y);
void InitBoard (int GameBoard[ROW][COL], int row, int col);
void DisplayBoard(int GameBoard[ROW][COL], int row, int col);
void Game();