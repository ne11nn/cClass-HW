#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define EMPTY 0
#define WALL 1
#define APPLE 2
#define SNAKEHEAD 3
#define SNAKEBODY 4
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESCAPE 27
#define ROW 23
#define COL 42

typedef struct
{
    int XCoord;
    int YCoord;
} SnakeHead;

typedef struct
{
    int XCoord;
    int YCoord;
} SnakeBody;

typedef struct
{
    SnakeHead head;
    SnakeBody body[965];
    int size;
    int direction;
} Snake;

void color (int c);
void CursorJump (int x, int y);
void InitBoard (int SnakeStartLength);
void DisplayBoard ();
void UpdateBoard (int xCoord, int yCoord, int item);
void SpawnApple ();
void HandleInput (int *x, int *y);
void MoveSnake (int x, int y);
void GameLoop ();
void Game ();