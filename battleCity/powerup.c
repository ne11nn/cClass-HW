#include "powerup.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void Gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x+1;
	pos.Y = y+1;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void initiatePowerup(int x, int y, int powerupType)
{
    switch (powerupType)
    {
        case PSCORE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PSPEED:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
            Gotoxy(x,y);
            printf("■"); 
            break; //

        case PWATER:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_BLUE|BACKGROUND_RED);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PEXPLOSIVE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|BACKGROUND_RED);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PPOWER:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PHEALING:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|BACKGROUND_GREEN);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PDEFENSE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_GREEN);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PLIFE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PSHIELD:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE);
            Gotoxy(x,y);
            printf("■"); 
            break;

        case PVISION:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE);
            Gotoxy(x,y);
            printf("■"); 
            break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}