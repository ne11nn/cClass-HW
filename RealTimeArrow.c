#include <stdio.h>
#include <conio.h>

int main()
{
    while (1)
    {
        int ch = getch();
        if (ch == 72)
        {
            printf("UP\n");
        }
        else if (ch == 80)
        {
            printf("DOWN\n");
        }
        else if (ch == 75)
        {
            printf("LEFT\n");
        }
        else if (ch == 77)
        {
            printf("RIGHT\n");
        }
        else if (ch == 27)
        {
            break;
        }
    }

    return 0;
}