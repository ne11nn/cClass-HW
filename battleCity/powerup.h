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

void initiatePowerup (int x, int y, int powerupType);