#include "battleCity.h"

void getHighScore()
{
    FILE *fp = NULL;
    fp = fopen("D:/Coding/C/cClass/battleCity/scoreinfo.txt", "r");

    fscanf(fp, "%d", &highscore);
    fclose(fp);
}

void updateHighScore()
{
    highscore = score;
    GoToxy(COL + 2, 10);
    printf("Highscore: %d", highscore);

    FILE *fp = NULL;

    fp = fopen("D:/Coding/C/cClass/battleCity/scoreinfo.txt", "w+");
    fprintf(fp, "%d", highscore);
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
        GoToxy((tank.x-1), tank.y-1+i);
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
        GoToxy((tank.x-1), tank.y-1+i);
        printf("%s", tankF[i][tank.direction]);
        for (int j = 0; j < 3; j++)
        {
            gameBoard[tank.y+j-1][tank.x+i-1] = ETANK;
        }
    }
    GoToxy(0,ROW+5);
}

void clearEnemyTank(EnemyTank tank)
{
    char clear = ' ';
    for (int i = 0; i < 3; i++)
    {
        GoToxy((tank.x-1), tank.y-1+i);
        printf("%c%c%c", clear, clear, clear);
        for (int j = 0; j < 3; j++)
        {
            gameBoard[tank.y+j-1][tank.x+i-1] = EMPTY;
        }
    }
}

void clearSpawnTank()
{
    char clear = ' ';
    for (int i = 0; i < 3; i++)
    {
        GoToxy((myTank.x-1), myTank.y-1+i);
        printf("%c%c%c", clear, clear, clear);
        for (int j = 0; j < 3; j++)
        {
            gameBoard[myTank.y+j-1][myTank.x+i-1] = EMPTY;
        }
    }

    initiateTank();
    printTank(myTank);
}

void updateScore()
{
    GoToxy(COL + 2, 7);
    printf("Score: %d", score);
}

void updateTanksLeft()
{
    GoToxy(COL + 2, 13);
    printf("Tanks Left: %d/%d", tanksRemaining,originalTanks);
}

void updateLives()
{
    GoToxy(COL + 2, 16);
    printf("Lives left: %d", lives);
}

void printBullet(Bullet bullet)
{
    GoToxy(bullet.x, bullet.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
    printf("O");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}