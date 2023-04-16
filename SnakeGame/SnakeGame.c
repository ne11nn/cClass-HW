#include "SnakeGame.h"

Snake snake;
int GameBoard[ROW][COL];
int highscore;

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

void DisplayBoard()
{
    system("cls");
    int i = 0;
    char strVal = ' ';
    for (i = 0; i < ROW; i++)
    {
        printf("\n");
        int j = 0;
        for (j = 0; j < COL; j++)
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
    printf("\nScore: 0              Highscore: %d", highscore);
}

void UpdateBoard(int xCoord, int yCoord, int item)
{
    char strVal = ' ';
    CursorJump(xCoord-1, yCoord);
    if (item == APPLE)
    {
        color(192);
        printf("%c",strVal);
    }
    else if (item == EMPTY)
    {
        color(0);
        printf("%c",strVal);
    }
    else if (item == SNAKEHEAD)
    {
        color(96);
        printf("%c",strVal);
    }
    else if (item == SNAKEBODY)
    {
        color(162);
        printf("%c",strVal);
    }
    color(7);
}

void SpawnApple()
{
    int XCoord;
    int YCoord;
    do
    {
        XCoord = rand() % ROW;
        YCoord = rand() % COL;
    } while (GameBoard[XCoord][YCoord] != EMPTY);
    GameBoard[XCoord][YCoord] = APPLE;
    UpdateBoard(YCoord,XCoord,APPLE);
}

void MoveSnake(int x, int y)
{
    GameBoard[snake.head.XCoord][snake.head.YCoord] = EMPTY;
    UpdateBoard(snake.head.YCoord,snake.head.XCoord,EMPTY);

    GameBoard[snake.body[snake.size-1].XCoord][snake.body[snake.size-1].YCoord] = EMPTY;
    UpdateBoard(snake.body[snake.size-1].YCoord,snake.body[snake.size-1].XCoord,EMPTY);

    int i = snake.size;

    for (i = snake.size; i > 1; i--)
    {
        snake.body[i-1].XCoord = snake.body[i-2].XCoord;
        snake.body[i-1].YCoord = snake.body[i-2].YCoord;
        GameBoard[snake.body[i-1].XCoord][snake.body[i-1].YCoord] = SNAKEBODY;
        UpdateBoard(snake.body[i-1].YCoord,snake.body[i-1].XCoord,SNAKEBODY);
    }

    snake.body[0].XCoord = snake.head.XCoord;
    snake.body[0].YCoord = snake.head.YCoord;
    GameBoard[snake.body[0].XCoord][snake.body[0].YCoord] = SNAKEBODY;
    UpdateBoard(snake.body[0].YCoord,snake.body[0].XCoord,SNAKEBODY);

    snake.head.XCoord = snake.head.XCoord + x;
    snake.head.YCoord = snake.head.YCoord + y;

    // switch (dir)
    // {
    //     case UP:
    //         snake.head.XCoord = snake.head.XCoord - 1;
    //         break;
        
    //     case DOWN:
    //         snake.head.XCoord = snake.head.XCoord + 1;
    //         break;

    //     case LEFT:
    //         snake.head.YCoord = snake.head.YCoord - 1;
    //         break;

    //     case RIGHT:
    //         snake.head.YCoord = snake.head.YCoord + 1;
    //         break;
    // }

    GameBoard[snake.head.XCoord][snake.head.YCoord] = SNAKEHEAD;
    UpdateBoard(snake.head.YCoord,snake.head.XCoord,SNAKEHEAD);
}

void HandleInput(int *x, int *y)
{    
    if (kbhit())
    {
        int ch = getch();

        switch (ch)
        {
            case UP:
                if (snake.direction != DOWN)
                {
                    snake.direction = UP;
                    *x = -1;
                    *y = 0;
                    break;
                }

            case DOWN:
                if (snake.direction != UP)
                {
                    snake.direction = DOWN;
                    *x = 1;
                    *y = 0;
                    break;
                }

            case LEFT:
                if (snake.direction != RIGHT)
                {
                    snake.direction = LEFT;
                    *x = 0;
                    *y = -1;
                    break;
                }

            case RIGHT:
                if (snake.direction != LEFT)
                {
                    snake.direction = RIGHT;
                    *x = 0;
                    *y = 1;
                    break; 
                }
        }
    }
}

void JudgeMovement(int x, int y)
{
    int i = 0;
    int j = 0;
    char result;
    switch (GameBoard[snake.head.XCoord + x][snake.head.YCoord + y])
    {
        case APPLE:
            GameBoard[snake.head.XCoord + x][snake.head.YCoord + y] = EMPTY;
            snake.size += 1;
            IncreaseScore();
            if (snake.score > highscore)
            {
                highscore = snake.score;
                UpdateHighScore();
            }
            SpawnApple();
            break;

        case WALL:
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    UpdateBoard(j, i, EMPTY);
                }
            }
            Sleep(350);
            CursorJump(15, 12);
            printf("GAME OVER");
            CursorJump(15,13);
            printf("PLAY AGAIN? [y/n]: ");
            result = getchar();
            getchar();
            
            if (result == 'y')
            {
                result = 'o';
                Game();
                break;
            }
            else
            {
                exit(1);
                break;
            }

        case SNAKEBODY:
            for (i = 0; i < ROW; i++)
            {
                for (j = 0; j < COL; j++)
                {
                    UpdateBoard(j, i, EMPTY);
                }
            }
            Sleep(350);
            CursorJump(15, 12);
            printf("GAME OVER");
            CursorJump(15,13);
            printf("PLAY AGAIN? [y/n]: ");
            result = getchar();
            getchar();
            
            if (result == 'y')
            {
                result = 'o';
                Game();
                break;
            }
            else
            {
                exit(1);
                break;
            }
    }
}

void GameLoop()
{
    int x, y;
    x = 0;
    y = 1;
    while (1)
    {
        HandleInput(&x, &y);
        JudgeMovement(x, y);
        MoveSnake(x, y);
        Sleep(250);
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
}

void InitBoard(int SnakeStartLength)
{
    int i = 0;

    for (i = 0; i < ROW; i++)
    {
        int j = 0;
        for (j = 0; j < COL; j++)
        {
            if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
            {
                GameBoard[i][j] = WALL;
            }
            else
            {
                GameBoard[i][j] = EMPTY;
            }
        }
    }

    int StartingPositionX = ROW / 2;
    int StartingPositionY = COL / 2;

    SnakeHead SnakeHeadCharacter;
    SnakeHeadCharacter.XCoord = StartingPositionX;
    SnakeHeadCharacter.YCoord = StartingPositionY;

    snake.head = SnakeHeadCharacter;
    snake.size = SnakeStartLength;
    snake.direction = RIGHT;
    snake.score = 0;
    
    GameBoard[snake.head.XCoord][snake.head.YCoord] = SNAKEHEAD;

    i = 0;
    for (i = 0; i < snake.size; i++)
    {
        SnakeBody TempBody;
        TempBody.XCoord = StartingPositionX;        
        TempBody.YCoord = StartingPositionY - i - 1;
        snake.body[i] = TempBody;
        GameBoard[TempBody.XCoord][TempBody.YCoord] = SNAKEBODY;
    }

    int XCoord;
    int YCoord;
    do
    {
        XCoord = rand() % ROW;
        YCoord = rand() % COL;
    } while (GameBoard[XCoord][YCoord] != EMPTY);
    GameBoard[XCoord][YCoord] = APPLE;
}

void GetHighScore()
{
    FILE *fp = NULL;

    fp = fopen("D:/Coding/C/cClass/SnakeGame/scoreinfo.txt", "r");
    fscanf(fp, "%d", &highscore);
    fclose(fp);
}

void UpdateHighScore()
{
    CursorJump(32,23);
    printf("%d",highscore);
    FILE *fp = NULL;

    fp = fopen("D:/Coding/C/cClass/SnakeGame/scoreinfo.txt", "w+");
    fprintf(fp, "%d", highscore);
    fclose(fp);
}

void IncreaseScore()
{
    snake.score += 10;
    CursorJump(6,23);
    printf("%d",snake.score);
}

void Game()
{
    system("cls");

    int GameBoard[ROW][COL];
    
    GetHighScore();
    InitBoard(3);
    DisplayBoard();
    Sleep(400);
    GameLoop();
    
    CursorJump(1,23);
}

void main()
{
    srand(time(NULL));
    Game();
}