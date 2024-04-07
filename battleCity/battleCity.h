#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

#define ROW 43
#define COL 43

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define UPKEY 72
#define DOWNKEY 80
#define LEFTKEY 75
#define RIGHTKEY 77
#define SMALLFKEY 102
#define BIGFKEY 70

// Environmental Objects
#define EMPTY 0
#define REGWALL 1
#define OUTERWALL 2
#define REINWALL 3
#define POWERWALL 4
#define WATER 5
#define TREE 6
#define HOME 7

// Interactive Objects
#define PTANK 8
#define ETANK 9
#define MYBULLET 10
#define BULLET1 11
#define BULLET2 12
#define BULLET3 13
#define POWERUP 14

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
int score = 0;

int numTanks[6]; /* number of enemy tanks alive for each enemy tank type
Index 0: Regular
Index 1: Agility
Index 2: Defense
Index 3: Attack
Index 4: Water
Index 5: Explosive
*/ 
int tanksRemaining;
int originalTanks;
int tanksOnField = 0;

int gameBoard[ROW][COL];

int cycle = 0;

// structure definitions

// MyTank
typedef struct
{
    char username[100];
    char tankeName[50];
    int x;
    int y;
    int type; 
    int shape; // (0, 1, 2, 3) based off tank_figure var
    int direction;
    int speed;
    int bulletPower;
    int bulletSpeed;
    int health;
    int lives;
    int activePowerup;

} MyTank;

// EnemyTank
typedef struct
{
    char tankName[50];
    int x;
    int y;
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

typedef struct
{
    int x;
    int y;
    int speed;
    int direction;
    int available;
    int power;
    
} Bullet;

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
void moveEnemyTank (EnemyTank *tank);
void hideCursor (int on);
void printTank (MyTank tank);
void printBullet (Bullet bullet);
void printEnemyTank (EnemyTank tank);
void GoToxy (int x, int y); 
void initiateTank ();
void myBulletSpawning (MyTank tank);
int judgeBulletMovement (int x, int y);
int judgeTank (int x, int y);
void moveSelfBullet ();
void initiateMap (int mapNumber);
void displayMap (int mapNumber);
void startScreen ();
void moveTank (int x, int y);
void getInput (int *x, int *y, int *xG, int *yG);
int judgeMovement (int x, int y);
void gameLoop ();
void game ();

void printGameBoard();