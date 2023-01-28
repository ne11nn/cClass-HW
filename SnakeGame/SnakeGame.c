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

void UpdateBoard(int GameBoard[ROW][COL], int row, int col)
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
    UpdateBoard(GameBoard, row, col);
}

void SpawnSnake(int GameBoard[ROW][COL], int row, int col, int StartLength)
{
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

    int StartingPositionX = row / 2;
    int StartingPositionY = col / 2;

    SnakeHead SnakeHeadCharacter;
    SnakeHeadCharacter.XCoord = StartingPositionX;
    SnakeHeadCharacter.YCoord = StartingPositionY;

    Snake SnakeCharacter;
    SnakeCharacter.head = SnakeHeadCharacter;
    SnakeCharacter.size = StartLength;
    SnakeCharacter.direction = RIGHT;

    int i = 0;
    for (i = 0; i < SnakeCharacter.size; i++)
    {
        SnakeBody TempBody;
        TempBody.XCoord = StartingPositionX;        
        TempBody.YCoord = StartingPositionY - i - 1;
        SnakeCharacter.body[i] = TempBody;
        GameBoard[TempBody.XCoord][TempBody.YCoord] = SNAKEBODY;
    }
    GameBoard[SnakeCharacter.head.XCoord][SnakeCharacter.head.YCoord] = SNAKEHEAD;
    UpdateBoard(GameBoard,row,col);
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
    UpdateBoard(GameBoard,row,col);
}

void Game()
{
    int GameBoard[ROW][COL];

    InitBoard(GameBoard,ROW,COL);
    Sleep(400);
    SpawnSnake(GameBoard,ROW,COL,3);
    Sleep(400);
    SpawnApple(GameBoard,ROW,COL);
}

void main()
{
    srand(time(NULL));
    Game();
}