#include "battleCity.h"

MyTank myTank;

EnemyTank tank1;
EnemyTank tank2;
EnemyTank tank3;

void getHighScore()
{
    FILE *fp = NULL;
    fp = fopen("D:/Coding/C/cClass/battleCity/scoreinfo.txt", "r");

    fscanf(fp, "%d", &highscore);
    fclose(fp);
}

void hideCursor(int on)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   if (on == 0)
   {
        info.bVisible = TRUE;
   }
   else
   {
        info.bVisible = FALSE;
   }
   SetConsoleCursorInfo(consoleHandle, &info);
}

void GoToxy(int x, int y)
{
	COORD pos;
	pos.X = x+1;
	pos.Y = y+1;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void printTank(MyTank tank)
{
    char *(*tankF)[4] = tank_figure[tank.shape];
    for (int i = 0; i < 3; i++)
    {
        GoToxy((tank.x-1)*2, tank.y-1+i);
        printf("%s", tankF[i][tank.direction]);
        for (int j = 0; j < 3; j++)
        {
            gameBoard[tank.y+j-1][tank.x+i-1] = PTANK;
        }
    }
    GoToxy(0,ROW+5);
}

void printEnemyTank(EnemyTank tank)
{
    char *(*tankF)[4] = tank_figure[tank.shape];
    for (int i = 0; i < 3; i++)
    {
        GoToxy((tank.x-1)*2, tank.y-1+i);
        printf("%s", tankF[i][tank.direction]);
        for (int j = 0; j < 3; j++)
        {
            gameBoard[tank.y+j-1][tank.x+i-1] = ETANK;
        }
    }
    GoToxy(0,ROW+5);
}

/*
void initiateMap (int mapNumber)
Creates map landscape for level mapNumber and resets enemy tank amount

Args:
    int mapNumber - the level number (1-5) wanted to be generated

Returns:
    NULL
*/

void initiateMap(int mapNumber)
{
    FILE *fp = NULL;

    char finalFileName[100];
    snprintf(finalFileName, sizeof(finalFileName), "D:/Coding/C/cClass/battleCity/mapInfo/map%d.txt", mapNumber);

    fp = fopen(finalFileName, "r");
    

    for (int i = 0; i < 6; i++)
    {
        fscanf(fp, "%d", &numTanks[i]);
        //printf("%d\n", numTanks[i]);
    }

    int length = sizeof(numTanks)/sizeof(numTanks[0]);    
    
    for (int i = 0; i < length; i++)
    {
        tanksRemaining += numTanks[i];
    }

    originalTanks = tanksRemaining;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            fscanf(fp, "%d", &gameBoard[i][j]);
            //printf("%d ", gameBoard[i][j]);
        }
        //printf("\n");
    }

    fclose(fp);

    myTank.x = COL/2 - 5;
    myTank.y = 38;
    myTank.shape = myTank.type - 1;
    myTank.direction = 0;

    switch (myTank.type)
    {
        case 1:
            myTank.speed = 2;
            myTank.bulletPower = 1;
            myTank.bulletSpeed = 2;
            myTank.health = 3;
            myTank.lives = 4;
            break;

        case 2:
            myTank.speed = 4;
            myTank.bulletPower = 1;
            myTank.bulletSpeed = 2;
            myTank.health = 3;
            myTank.lives = 3;
            break;

        case 3:
            myTank.speed = 3;
            myTank.bulletPower = 2;
            myTank.bulletSpeed = 2;
            myTank.health = 2;
            myTank.lives = 3;
            break;

        case 4:
            myTank.speed = 1;
            myTank.bulletPower = 2;
            myTank.bulletSpeed = 2;
            myTank.health = 5;
            myTank.lives = 3;
            break;
    }
}

void displayMap(int mapNumber)
{
    char strVal = ' ';
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            switch (gameBoard[i][j])
            {
                case REGWALL:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_GREEN|BACKGROUND_RED);
				    GoToxy(2*j,i);
				    printf("▓▓"); 
                    break;

                case OUTERWALL:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN
					    |FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN
					    |FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
				    GoToxy(2*j,i);
				    printf("■■");
                    break;

                case REINWALL:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED
                        |BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED);
                    GoToxy(2*j,i);
				    printf("■■");
                    break;

                case HOME:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED
                        |BACKGROUND_RED);
                    GoToxy(2*j,i);
                    printf("■■");
                    break;

                case EMPTY:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN
			        |FOREGROUND_RED|FOREGROUND_BLUE);
                    GoToxy(2*j,i);
                    printf("%c",strVal);
                    break;
            }
        }
    }

    GoToxy(COL*2 + 2,3);
    printf("Level: %d", mapNumber);
    GoToxy(COL*2 + 2, 8);
    printf("Score: %d", score);
    GoToxy(COL*2 + 2, 13);
    printf("Tanks Left: %d/%d", tanksRemaining,originalTanks);
    GoToxy(COL*2 + 2, 18);
    printf("Lives left: %d", myTank.lives);
    GoToxy(COL*2 + 2, 23);
    printf("Controls:");

    GoToxy(myTank.x,myTank.y);
    printTank(myTank);
}

void startScreen()
{
    GoToxy(30,15);
    printf("Battle City");
    GoToxy(28,16);
    printf("Choose your tank");
    GoToxy(15,20);
    printf("Normal: A regular tank that has no special traits - 1");
    for (int i = 0; i < 3; i++)
    {
        GoToxy(15,22+i);
        printf("%s", tank_figure[0][i][0]);
    }
    GoToxy(15,26);
    printf("Agility: A tank that has faster speed but less lives - 2");
    for (int i = 0; i < 3; i++)
    {
        GoToxy(15,28+i);
        printf("%s", tank_figure[1][i][0]);
    }
    GoToxy(15,32);
    printf("Attack: A tank that has a little more speed, more damage but less health and lives - 3");
    for (int i = 0; i < 3; i++)
    {
        GoToxy(15,34+i);
        printf("%s", tank_figure[2][i][0]);
    }
    GoToxy(15,38);
    printf("Defense: A tank that's slow and has more damage and has more health - 4");
    for (int i = 0; i < 3; i++)
    {
        GoToxy(15,40+i);
        printf("%s", tank_figure[3][i][0]);
    }

    myTank.type = -1;

    int n = 0; // how many times player fails to type a number 1 - 4
    while (myTank.type != 1 && myTank.type != 2 && myTank.type != 3 && myTank.type != 4)
    {
        GoToxy(15,44 + n);
        printf("Pick your tank by typing in a number (1 - 4): ");
        scanf("%d",&myTank.type);
        n += 1;
    }

    Sleep(500);
    system("cls");
}

void moveTank(int x, int y)
{
    char empty = ' ';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            GoToxy((myTank.x-1)*2+j , myTank.y-1+i);
            printf("%c",empty);
        

            gameBoard[myTank.y+j-1][myTank.x+i-1] = EMPTY;
        } 
    }
    

    myTank.y += y;
    myTank.x += x;

    printTank(myTank);
    
}

void moveEnemyTank(EnemyTank *tank)
{
    char empty = ' ';
    int y, x;

    int direction = rand() % 4;

    switch (direction)
    {
        case UP:
            y = 1;
            x = 0;
            break;

        case DOWN:
            y = -1;
            x = 0;
            break;

        case RIGHT:
            y = 0;
            x = 1;
            break;

        case LEFT:
            y = 0;
            x = -1;
            break;
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            GoToxy((tank->x-1)*2+j, tank->y-1+i);
            printf("%c",empty);
            gameBoard[tank->y+j-1][tank->x+i-1] = EMPTY;
        }
    }

    (*tank).y += y;
    (*tank).x += x;

    printEnemyTank(*tank);
}

void getInput(int *x, int *y, int *xG, int *yG)
{
    if (kbhit())
    {
        int ch = getch();
        
        switch (ch)
        {
            case UPKEY:
                myTank.direction = UP;
                *x = 0;
                *y = -1;
                *xG = 0;
                *yG = -1;
                break;

            case DOWNKEY:
                myTank.direction = DOWN;
                *x = 0;
                *y = 1;
                *xG = 0;
                *yG = 1;
                break;

            case LEFTKEY:
                myTank.direction = LEFT;
                *x = -1;
                *y = 0;
                *xG = -1;
                *yG = 0;
                break;

            case RIGHTKEY:
                myTank.direction = RIGHT;
                *x = 1;
                *y = 0;
                *xG = 1;
                *yG = 0;
                break;
        }
    }

    else
    {
        *x = 0;
        *y = 0;
    }
}

int judgeEnemyTankSpawning (EnemyTank *tank)
{
    if (gameBoard[tank->x-1][tank->y-1] != 0 || gameBoard[tank->x-1][tank->y] != 0 || gameBoard[tank->x-1][tank->y+1] != 0
    || gameBoard[tank->x][tank->y-1] != 0 || gameBoard[tank->x][tank->y] != 0 || gameBoard[tank->x][tank->y+1] != 0
    || gameBoard[tank->x+1][tank->y-1] != 0 || gameBoard[tank->x+1][tank->y] != 0 || gameBoard[tank->x+1][tank->y+1])
    {
        return 0;
    }
    return 1;
}

void tankSpawning(EnemyTank *tank)
{
    int tankType;

    tankType = rand() % 2;
    while (numTanks[tankType] < 0)
    {
        tankType = rand() % 2;
    }

    numTanks[tankType] -= 1;

    // create enemytank object

    tank->y = 2;
    tank->x = rand() % (COL + 1);
    tank->direction = 4;
    tank->type = tankType;
    
    switch (tank->type)
    {
        case 0:
            tank->speed = 2;
            tank->bulletPower = 1;
            tank->bulletSpeed = 2;
            tank->health = 2;
            break;
        
        case 1:
            tank->speed = 5;
            tank->bulletPower = 1;
            tank->bulletSpeed = 5;
            tank->health = 1;
            break;
    }

    // turn into function
    while (judgeEnemyTankSpawning(tank) == 0)
    {
        tank->x = rand() % (COL + 1);
    }

    for (int i = 0; i < 3; i++)
    {
        GoToxy((tank->x-1)*2, tank->y-1+i);
        for (int j = 0; j < 3; j++)
        {
            gameBoard[tank->y+j][tank->x+i] = ETANK;
        }
    }

    printEnemyTank(*tank);
    tanksOnField += 1;
}

int judgeMovement(int x, int y)
{
    if (gameBoard[myTank.x + 2*x][myTank.y - 2*y] != EMPTY)
    {
        return 1;
    }
    return 0;
}

void gameLoop()
{
    int x, y, xG, yG;
    int tankType;
    xG = 0;
    yG = -1;
    x = 0;
    y = 0;
    while (1)
    {
        loopCount ++;
        if (tanksOnField < 3)
        {
            if (tank1.health <= 0)
            {
                tankSpawning(&tank1);
            }
            else if (tank2.health <= 0)
            {
                tankSpawning(&tank2);
            }
            else if (tank3.health <= 0)
            {
                tankSpawning(&tank3);
            }
        }

        getInput(&x, &y, &xG, &yG);     // -1,0|0,0  up,none 

        //printf("%d - %d", x, y);
        judgeMovement(x, y);
        if (judgeMovement(xG, yG) == 0)
        {
            moveTank(x, y);
        }
    
        moveEnemyTank(&tank1);
        moveEnemyTank(&tank2);
        moveEnemyTank(&tank3);
        GoToxy(0,ROW+5);
        Sleep(50);
    }
}

void game()
{
    startScreen();
    hideCursor(1);
    initiateMap(1);
    displayMap(1);
    gameLoop();
}

void main()
{
    srand(time(NULL));
    getHighScore();
    system("cls");
    game();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    GoToxy(COL*2,ROW);
    hideCursor(0);
}