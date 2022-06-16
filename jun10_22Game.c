#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <ctype.h>

//decides if the number guessed by player is higher than computer generated number or not
void higherOrLower(int playerNumber, int goalNumber)
{
    if (playerNumber > goalNumber)
    {
        printf("My number is lower\n");
    }

    if (playerNumber < goalNumber)
    {
        printf("My number is higher\n");
    }
}

//decides if the number the player guessed is odd or even
void oddOrEven(int goalNumber)
{
    if (goalNumber % 2 == 1)
    {
        printf("My number is odd\n");
    }
    else
    {
        printf("My number is even\n");
    }
}

//decides if the number the player guessed is prime or not
void primeOrNot(int goalNumber)
{
    int primeFlag = 0;

    if (goalNumber == 0 || goalNumber == 1) //if the number is 0 or 1 it's prime
    {
        primeFlag = 1;
    }

    for (int i = 2; i <= goalNumber / 2; ++i) //checks if all numbers below the number is a factor of the number or not
    {
        if (goalNumber % i == 0) //if it is divisible then set primeflag to 1
        {
            primeFlag = 1;
            break;
        }
    }

    if (primeFlag == 0)
    {
        printf("My number is prime\n");
    }
    if (primeFlag == 1)
    {
        printf("My number is not prime\n");
    }
}

//function ran when players wins
void whenPlayerWins()
{
    char secondPlayerInput = 'a';

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
        printf("Do you want to play again?\n(y/n): ");
        secondPlayerInput = getchar();
    }
}

//function ran when player loses
void whenPlayerLoses(int number)
{
    char secondPlayerInput = 'f';

    printf("Nice try but ");
    Sleep(200);
    printf("my number was %d\n",number);
    Sleep(300);

    while (secondPlayerInput != 'y')
    {
        if (secondPlayerInput == 'n')
        {
            printf("Bye!");
            Sleep(1500);
            exit(1);
        }
        printf("Do you want to play again?\n(y/n): ");
        secondPlayerInput = getchar();
    }
}

int startGame(int number)
{
    int playerGuess = -1;
    int methodOfHint;
    int tempNumber = number;
    int sumOfDigits = 0;
    int m = 0;

    Sleep(1000);
    printf("I got my number!\n");
    Sleep(800);
    for (int i = 0; i < 4; ++i)
    {
        playerGuess = -1;
        while(playerGuess > 100 || playerGuess < 0)
        {
            printf("What's your guess? ");
            scanf("%d",&playerGuess);
            Sleep(750);
        }

        if (playerGuess == number)
        {
            whenPlayerWins();
            startGame(rand() %101);
            return 0;
        }

        if (playerGuess != number)
        {
            printf("Oops! You got it wrong!\n");
            Sleep(400);
            if (i != 3)
            {
                higherOrLower(playerGuess,number);
            }
            Sleep(400);

            if (i == 1)
            {
                oddOrEven(number);
            }

            if (i == 2)
            {
                primeOrNot(number);
            }

            if (i == 3)
            {
                whenPlayerLoses(number);
                startGame(rand() %101);
                return 0;
            }
        }
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
        printf("Welcome to a number guessing game. \nI will choose a random number from 0-100\nand you will have to guess the number in 4 tries. \nI will also give hints if you get them wrong. \nIf you are up to the challenge, type in y. If not then type in n. \nGood luck!\n(y/n): ");
        scanf("%c",&beginningInput);
    }

    startGame(rand() %101);
}