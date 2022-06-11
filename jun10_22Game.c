#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>

void append(char* originalString, char appendingString)
{
    int len = strlen(originalString);
    originalString[len] = appendingString;
    originalString[len+1] = '\0';
}

void startGame(int number)
{
    printf("%d\n",number);
    int playerGuess = -1;
    char secondPlayerInput = 'f';
    int methodOfHint;
    int primeFlag = 0;
    int tempNumber = number;
    int sumOfDigits = 0;
    int m = 0;
    char methodsAlrUsed[] = "6";

    char tmpZero[2] = "0";
    char tmpOne[2] = "1";
    char tmpTwo[2] = "2";

    while (tempNumber > 0)
    {
        m = tempNumber % 10;
        sumOfDigits = sumOfDigits + m;
        tempNumber = tempNumber/10;
    }

    /*
        0 = prime/composite
        1 = odd/even
        2 = sum of digits
    */

    Sleep(1000);
    printf("I got my number!\n");
    Sleep(800);
    for (int i = 0; i < 3; ++i)
    {
        printf("%c",methodsAlrUsed);
        while(playerGuess > 100 || playerGuess < 0)
        {
            printf("What's your guess? ");
            scanf("%d",&playerGuess);
            Sleep(750);
        }

        if (playerGuess == number)
        {
            printf("You got it correct. Nice job!\n");
            Sleep(300);
            while (secondPlayerInput != 'y')
            {
                if (secondPlayerInput == 'n')
                {
                    printf("Bye!");
                    Sleep(1500);
                    exit(1);
                }
                printf("Do you want to play again?");
                Sleep(300);
                printf("(y/n): ");
                scanf("%c",&secondPlayerInput);
            }

            startGame(rand() %101);
            return;
        }

        if (playerGuess != number)
        {
            printf("Oops! You got it wrong!\n");
            Sleep(400);
            if (number > playerGuess)
            {
                printf("My number is higher\n");
            }
            else
            {
                printf("My number is lower\n");
            }
            Sleep(400);
            
            methodOfHint = 6;

            while(strchr(methodsAlrUsed,methodOfHint) != NULL)
            {
                methodOfHint = rand() % 3;

                if (strchr(methodsAlrUsed,methodOfHint) == NULL)
                {
                    if (methodOfHint == 0)
                    {
                        if (number == 0 || number == 1)
                        {
                            primeFlag = 1;
                        }

                        for (int i = 2; i <= number / 2; ++i)
                        {
                            if (number % i == 0)
                            {
                                primeFlag = 1;
                                break;
                            }
                        }

                        if (primeFlag == 0)
                        {
                            printf("My number is prime");
                        }
                        if (primeFlag == 1)
                        {
                            printf("My number is not prime");
                        }

                       strcat(methodsAlrUsed,tmpZero);
                    }

                    if (methodOfHint == 1)
                    {
                        if (number % 2 == 1)
                        {
                            printf("My number is odd");
                        }
                        else
                        {
                            printf("My number is even");
                        }
                        
                        strcat(methodsAlrUsed,tmpOne);
                    }

                    if (methodOfHint == 2)
                    {
                        printf("The sum of my digits is %d",sumOfDigits);
                        

                        strcat(methodsAlrUsed,tmpTwo);
                    }
                }
            }
        }

        playerGuess = -1;
        secondPlayerInput = 'f';
        primeFlag = 0;
        tempNumber = number;
        sumOfDigits = 0;
        m = 0;
    }

    while(playerGuess > 100 || playerGuess < 0)
    {
        printf("What's your guess? ");
        scanf("%d",&playerGuess);
        Sleep(750);
    }

    if (playerGuess == number)
    {
        printf("You got it correct. Nice job!\n");
        Sleep(300);
        while (secondPlayerInput != 'y')
        {
            if (secondPlayerInput == 'n')
            {
                printf("Bye!");
                Sleep(1500);
                exit(1);
            }
            printf("Do you want to play again?");
            Sleep(300);
            printf("(y/n): ");
            scanf("%c",&secondPlayerInput);
        }

        startGame(rand() %101);
        return;
    }

    if (playerGuess != number)
    {
        printf("Oops! You got it wrong!\n");
        Sleep(500);
        printf("My number was %d\n",number);
        Sleep(500);
        while (secondPlayerInput != 'y')
        {
            if (secondPlayerInput == 'n')
            {
                printf("Bye!");
                Sleep(1500);
                exit(1);
            }
            printf("Would you like to try again?");
            Sleep(300);
            printf("(y/n): ");
            scanf("%c",&secondPlayerInput);
        }

        startGame(rand() %101);
        return;
    }
    
}

void main()
{
    srand(time(NULL)); // Initialization for the random number function
    
    char beginningInput = 'f';
    while (beginningInput != 'y')
    {
        if (beginningInput == 'n')
        {
            exit(1);
        }
        printf("Welcome to a number guessing game. \nI will choose a random number from 0-100\nand you will have to guess the number. \nI will also give hints if you get them wrong. \nIf you are up to the challenge, type in y. If not then type in n. \nGood luck!\n(y/n): ");
        scanf("%c",&beginningInput);
    }

    startGame(rand() %101);
}