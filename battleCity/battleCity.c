#include "battleCity.h"

MyTank myTank;

void getHighScore()
{
    FILE *fp = NULL;
    fp = fopen("D:/Coding/C/cClass/battleCity/scoreinfo.txt", "r");

    fscanf(fp, "%d", &highscore);
    fclose(fp);
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
        printf("%s", tankF[i][tank.direction-1]);
        // for (int j = 0; j < 3; j++)
        // {
        //     if (tank.my)
        //         gameBoard[tank.y+j-1][tank.x+i-1] = 200;
        //     else   
        //         gameBoard[tank.y+j-1][tank.x+i-1] = 100+tank.num;
        // }
    }
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

    myTank.x = COL/2;
    myTank.y = 30;
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
    GoToxy(15,22);
    for (int i = 0; i < 3; i++)
    {
        printf("%s", tank_figure[0][i][0]);
        GoToxy(15,22+i);
    }
    GoToxy(15,25);
    printf("Agility: A tank that has faster speed but less lives - 2");
    GoToxy(15,28);
    for (int i = 0; i < 3; i++)
    {
        printf("%s", tank_figure[1][i][0]);
        GoToxy(15,28+i);
    }
    GoToxy(15,30);
    printf("Attack: A tank that has a little more speed, more damage but less health and lives - 3");
    GoToxy(15,32);
    for (int i = 0; i < 3; i++)
    {
        printf("%s", tank_figure[2][i][0]);
        GoToxy(15,32+i);
    }
    GoToxy(15,35);
    printf("Defense: A tank that's slow and has more damage and has more health - 4");
    GoToxy(15,37);
    for (int i = 0; i < 3; i++)
    {
        printf("%s", tank_figure[3][i][0]);
        GoToxy(15,37+i);
    }

    myTank.type = -1;

    int n = 0; // how many times player fails to type a number 1 - 4
    while (myTank.type != 1 && myTank.type != 2 && myTank.type != 3 && myTank.type != 4)
    {
        GoToxy(15,40 + n);
        printf("Pick your tank by typing in a number (1 - 4): ");
        scanf("%d",&myTank.type);
        n += 1;
    }

    switch (myTank.type)
    {
        case 1:
            myTank.lives = 4;
            break;
        
        case 2:
            myTank.lives = 3;
            break;

        case 3:
            myTank.lives = 3;
            break;
        
        case 4:
            myTank.lives = 4;
            break;
    }

    Sleep(500);
    system("cls");
}

void game()
{
    startScreen();
    initiateMap(1);
    displayMap(1);
}

void main()
{
    getHighScore();
    system("cls");
    srand(time(NULL));
    game();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    GoToxy(COL*2,ROW);
}