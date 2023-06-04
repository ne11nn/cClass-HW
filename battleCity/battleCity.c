#include "battleCity.h"

void getHighScore()
{
    FILE *fp = NULL;
    fp = fopen("D:/Coding/C/cClass/battleCity/scoreinfo.txt", "r");

    fscanf(fp, "%d", &highscore);
    fclose(fp);
}

void initiateMap(int mapNumber)
{
    FILE *fp = NULL;

    switch (mapNumber)
    {
        case 1:
            fp = fopen("D:/Coding/C/cClass/battleCity/mapInfo/map1.txt", "r");

        case 2:
            fp = fopen("D:/Coding/C/cClass/battleCity/mapInfo/map2.txt", "r");

        case 3:
            fp = fopen("D:/Coding/C/cClass/battleCity/mapInfo/map3.txt", "r");

        case 4:
            fp = fopen("D:/Coding/C/cClass/battleCity/mapInfo/map4.txt", "r");

        case 5:
            fp = fopen("D:/Coding/C/cClass/battleCity/mapInfo/map5.txt", "r");
    }

    for (int i = 0; i < 6; i++)
    {
        fscanf(fp, "%d", &numTanks[i]);
        printf("%d\n", numTanks[i]);
    }

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            fscanf(fp, "%d", &gameBoard[i][j]);
            printf("%d ", gameBoard[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
}

void game()
{
    initiateMap(1);
}

void main()
{
    getHighScore();
    system("cls");
    srand(time(NULL));
    game();
}