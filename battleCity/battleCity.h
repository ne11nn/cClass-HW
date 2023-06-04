#include <stdio.h>
#include <windows.h>
#include <time.h>

#define FALSE 0
#define TRUE 1

#define ROW 43
#define COL 65

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Game Objects
#define REGWALL 1
#define REINWALL 2
#define POWERWALL 3
#define WATER 4
#define TREE 5
#define PTANK 6
#define HOME 7
#define ETANK 8
#define BULLET 9
#define POWERUP 10

// MyTank category: M at the start
#define MREGULAR 0
#define MAGILITY 1
#define MATTACK 2
#define MDEFENSE 3

// EnemyTank category: E at the start
#define EREGULAR 0
#define EAGILITY 1
#define EDEFENSE 2
#define EATTACK 3
#define EWATER 4
#define EEXPLOSIVE 5

// Powerup category: P at the start
#define PSCORE 0
#define PSPEED 1
#define PWATER 2
#define PEXPLOSIVE 3
#define PPOWER 4
#define PHEALING 5
#define PDEFENSE 6
#define PLIFE 7
#define PSHIELD 8
#define PVISION 9

// tank shapes
char* tank_figure[4][3][4]=
{
  {
    {"◢┃◣", "◢━◣", "◢┳◣", "◢┳◣"},
    {"┣●┫", "┣●┫", "━●┃", "┃●━"},
    {"◥━◤", "◥┃◤", "◥┻◤", "◥┻◤"}
  },
  {
    {"┏┃┓", "┏┳┓", "┏┳┓", "┏┳┓"},
    {"┣●┫", "┣●┫", "━●┫", "┣●━"},
    {"┗┻┛", "┗┃┛", "┗┻┛", "┗┻┛"}
  },
  {
    {"┏┃┓", "◢━◣", "┏┳◣", "◢┳┓"},
    {"┣●┫", "┣●┫", "━●┃", "┃●━"},
    {"◥━◤", "┗┃┛", "┗┻◤", "◥┻┛"}
  },
  {
    {"╔┃╗", "╔╦╗", "╔╦╗", "╔╦╗"},
    {"╠█╣", "╠█╣", "━█╣", "╠█━"},
    {"╚╩╝", "╚┃╝", "╚╩╝", "╚╩╝"}
  }
};

// global variables
int highscore;

int numTanks[6];

int gameBoard[ROW][COL];

// structure definitions

// MyTank
typedef struct
{
    char username[100];
    char tankeName[50];
    int type; 
    int color; // color value wanted
    int shape; // (0, 1, 2, 3) based off tank_figure var
    int direction;
    int speed;
    int bulletPower;
    int bulletDestruction;
    int bulletSpeed;
    int bulletReloadTime;
    int health;
    int lives;
    int score;
    int kill;
    int activePowerup;

} MyTank;

// EnemyTank
typedef struct
{
    char tankName[50];
    int type;
    int color; // color value wanted
    int shape; // (0, 1, 2, 3) based off tank_figure var
    int direction;
    int speed;
    int bulletPower;
    int bulletDestruction;
    int bulletSpeed;
    int bulletReloadTime;
    int health;
    int levelGenerated;
    int scoreGiven;

} EnemyTank;

// Landscape
typedef struct
{
    char description[100];
    int design; // (0, 1, 2, 3, 4) based off [TBD] var
    int color; // color value wanted
    char landscapeName[100];
    int type;
    int durability;
    int dropsPowerup;

} Landscape;

// Powerup
typedef struct
{
    char description[100];
    int design; // (0, 1, 2, 3, 4, 5, 6, 7, 8, 9) based off [TBD] var
    int color; // color value wanted
    char powerupName[100];
    int type;
    float duration;
    
} Powerup;

void getHighScore ();
void initiateMap (int mapNumber);
void game ();