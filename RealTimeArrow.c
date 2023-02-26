#include <stdio.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESCAPE 27

int main()
{
    while (1)
    {
        int ch = getch();
        if (ch == UP)
        {
            printf("UP\n");
        }
        else if (ch == DOWN)
        {
            printf("DOWN\n");
        }
        else if (ch == LEFT)
        {
            printf("LEFT\n");
        }
        else if (ch == RIGHT)
        {
            printf("RIGHT\n");
        }
        else if (ch == ESCAPE)
        {
            break;
        }
    }

    return 0;
}