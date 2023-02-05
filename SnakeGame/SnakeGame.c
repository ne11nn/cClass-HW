#include "SnakeGame.h"

void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void CursorJump(int x, int y)
{
	COORD pos;
	pos.X = x+1;
	pos.Y = y+1;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void DisplayBoard(int GameBoard[ROW][COL], int row, int col)
{
    system("cls");
    int i = 0;
    char strVal = ' ';
    for (i = 0; i < row; i++)
    {
        printf("\n");
        int j = 0;
        for (j = 0; j < col; j++)
        {
            if (GameBoard[i][j] == WALL)
            {
                color(224);
                printf("%c",strVal);
            }
            else if (GameBoard[i][j] == EMPTY)
            {
                color(0);
                printf("%c",strVal);
            }
            else if (GameBoard[i][j] == APPLE)
            {
                color(192);
                printf("%c",strVal);
            }
            else if (GameBoard[i][j] == SNAKEHEAD)
            {
                color(96); 
                printf("%c",strVal);
            }
            else if (GameBoard[i][j] == SNAKEBODY)
            {
                color(162);
                printf("%c",strVal);
            }
            // printf("%d ",GameBoard[i][j]);
        }
    }
    color(7);
}

void UpdateBoard(int GameBoard[ROW][COL], int row, int col, int xCoord, int yCoord, int item)
{
    char strVal = ' ';
    CursorJump(xCoord, yCoord);
    printf("\b \b");
    if (item == APPLE)
    {
        color(192);
        printf("%c",strVal);
    }
    else if(item == SNAKEHEAD)
    {
        color(96);
        printf("%c",strVal);
    }
    else if(item == SNAKEBODY)
    {
        color(162);
        printf("%c",strVal);
    }
    color(7);
}

void SpawnApple(int GameBoard[ROW][COL], int row, int col)
{
    int XCoord;
    int YCoord;
    do
    {
        XCoord = rand() % row;
        YCoord = rand() % col;
    } while (GameBoard[XCoord][YCoord] != EMPTY);
    GameBoard[XCoord][YCoord] = APPLE;
    UpdateBoard(GameBoard,row,col,YCoord,XCoord,APPLE);
}

void InitBoard(int GameBoard[ROW][COL], int row, int col, int SnakeStartLength)
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

    int StartingPositionX = row / 2;
    int StartingPositionY = col / 2;

    SnakeHead SnakeHeadCharacter;
    SnakeHeadCharacter.XCoord = StartingPositionX;
    SnakeHeadCharacter.YCoord = StartingPositionY;

    Snake SnakeCharacter;
    SnakeCharacter.head = SnakeHeadCharacter;
    SnakeCharacter.size = SnakeStartLength;
    SnakeCharacter.direction = RIGHT;
    
    GameBoard[SnakeCharacter.head.XCoord][SnakeCharacter.head.YCoord] = SNAKEHEAD;

    i = 0;
    for (i = 0; i < SnakeCharacter.size; i++)
    {
        SnakeBody TempBody;
        TempBody.XCoord = StartingPositionX;        
        TempBody.YCoord = StartingPositionY - i - 1;
        SnakeCharacter.body[i] = TempBody;
        GameBoard[TempBody.XCoord][TempBody.YCoord] = SNAKEBODY;
    }


    int XCoord;
    int YCoord;
    do
    {
        XCoord = rand() % row;
        YCoord = rand() % col;
    } while (GameBoard[XCoord][YCoord] != EMPTY);
    GameBoard[XCoord][YCoord] = APPLE;
}

void Game()
{
    int GameBoard[ROW][COL];

    InitBoard(GameBoard,ROW,COL,3);
    DisplayBoard(GameBoard,ROW,COL);
    Sleep(400);
    SpawnApple(GameBoard,ROW,COL);
    CursorJump(1,23);

    // int i = 0;
    // for (i = 0; i < ROW; i++)
    // {
    //     printf("\n");
    //     int j = 0;
    //     for (j = 0; j < COL; j++)
    //     {
    //         printf("%d",GameBoard[i][j]);
    //     }
    // }
}

void main()
{
    srand(time(NULL));
    Game();
}