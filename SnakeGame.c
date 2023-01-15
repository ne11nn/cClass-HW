#include "SnakeGame.h"

void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void CursorJump(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void DisplayBoard(int GameBoard[ROW][COL], int row, int col)
{
    int i = 0;
    char strVal = ' ';
    for (i = 0; i < row; i++)
    {
        printf("\n");
        int j = 0;
        for (j = 0; j < col; j++)
        {
            if (GameBoard[i][j] == 1)
            {
                color(224);
                printf("%c",strVal);
            }
            
            if(GameBoard[i][j] == 0)
            {
                color(0);
                printf("%c",strVal);
            }
            // printf("%d ",GameBoard[i][j]);
        }
    }
}

void InitBoard(int GameBoard[ROW][COL], int row, int col)
{
    int i = 0;

    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
            {
                GameBoard[i][j] = WALL;
            }
            else
            {
                GameBoard[i][j] = EMPTY;
            }
        }
    }
}

void Game()
{
    int GameBoard[ROW][COL];

    InitBoard(GameBoard,ROW,COL);
    DisplayBoard(GameBoard,ROW,COL);
    color(7);
}

void main()
{
    Game();
}