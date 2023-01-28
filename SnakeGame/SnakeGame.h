#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define EMPTY 0
#define WALL 1
#define APPLE 2
#define SNAKEHEAD 3
#define SNAKEBODY 4
#define UP 5
#define DOWN 6
#define LEFT 7
#define RIGHT 8
#define ROW 23
#define COL 42

void color (int c);
void CursorJump (int x, int y);
void InitBoard (int GameBoard[ROW][COL], int row, int col);
void UpdateBoard (int GameBoard[ROW][COL], int row, int col);
void SpawnApple (int GameBoard[ROW][COL], int row, int col);
void SpawnSnake (int GameBoard[ROW][COL], int row, int col, int StartLength);
void Game ();