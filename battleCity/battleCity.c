#include "battleCity.h"

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
    printf("Tanks Left: %d", tanksRemaining);
    GoToxy(COL*2 + 2, 18);
    printf("Controls:");
}

void startScreen()
{
    GoToxy(30,15);
    printf("Battle City");
    GoToxy(28,16);
    printf("Choose your tank");
    GoToxy(15,20);
    printf("Normal: A regular tank that has no special traits - 1");
    GoToxy(15,21);
    printf("Agility: A tank that has faster speed but less lives - 2");
    GoToxy(15,22);
    printf("Attack: A tank that has a little more speed, more damage but less health and lives - 3");
    GoToxy(15,23);
    printf("Defense: A tank that's slow and has more damage and has more health - 4");

    int n = 0; // how many times player fails to type a number 1 - 4
    while (playerTankType != 1 && playerTankType != 2 && playerTankType != 3 && playerTankType != 4)
    {
        GoToxy(15,24 + n);
        printf("Pick your tank by typing in a number (1 - 4): ");
        scanf("%d",&playerTankType);
        n += 1;
    }
    Sleep(1000);
    system("cls");
}

void game()
{
    initiateMap(1);
    printf("\n");
    startScreen();
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