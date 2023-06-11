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

void displayMap()
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

                case REINWALL:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN
					    |FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN
					    |FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
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
}

void game()
{
    initiateMap(1);
    printf("\n");
    displayMap();
}

void main()
{
    getHighScore();
    system("cls");
    srand(time(NULL));
    game();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}