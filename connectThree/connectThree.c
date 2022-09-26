#include "connectThree.h"

void displayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for(i = 0; i < row; i++)
    {
        int j = 0;
        for(j = 0; j < col; j++)
        {
            printf(" %c ",board[i][j]);
            if(j < col-1)
            {
                printf("|");
            }
        }
        printf("\n");

        if(i < row-1)
        {
            int j = 0;
            for(j = 0; j < col; j++)
            {
                printf("---");
                if(j < col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}
void placePiece(char board[ROW][COL], int rowPos, int colPos, int player)
{
    if(player == 1)
    {
        board[rowPos-1][colPos-1] = 'O';
    }
    else
    {
        board[rowPos-1][colPos-1] = 'X';
    }
}

void initBoard(char board[ROW][COL], int row, int col)
{
    /*
    player = O
    computer = X
    */
   int i = 0;
   char strVal = ' ';


   for(i = 0; i < row; i++)
   {
        int j = 0;
        for(j = 0; j < col; j++)
        {
            board[i][j] = strVal;
        }
   }
}

void computerPlay(char board[ROW][COL])
{
    int rowPos = rand() % 3 + 1;
    int colPos = rand() % 3 + 1;

    while(board[rowPos-1][colPos-1] == 'X' || board[rowPos-1][colPos-1] == 'O')
    {
        rowPos = rand() % 3 + 1;
        colPos = rand() % 3 + 1;
    }   
    placePiece(board, rowPos, colPos, 0);
}

int isDraw(char board[ROW][COL], int row, int col)
{
    int i;
    int flag = 0;
    for(i = 0; i < row; i++)
    {
        int j = 0;
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == 'X' || board[i][j] == 'O')
            {
                flag = flag + 1;
            }
        }
    }

    if (flag == row * col)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isRowWin(char board[ROW][COL], int row)
{
    /*
    2 = computer win
    1 = player win
    0 = no win
    */
    int i;
    for(i = 0; i < row; i++)
    {
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            return COMPUTER_WIN;
        }
        else if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            return PLAYER_WIN;
        }
    }
    return TIE;
}

int isColWin(char board[ROW][COL], int col)
{
    int j;
    for(j = 0; j < col; j++)
    {
        if(board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X')
        {
            return COMPUTER_WIN;
        }
        else if(board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O')
        {
            return PLAYER_WIN;
        }
    }
    return TIE;
}

int isDiagonalWin(char board[ROW][COL])
{
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {
        return COMPUTER_WIN;
    }
    else if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
    {
        return COMPUTER_WIN;
    }
    else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        return PLAYER_WIN;
    }
    else if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
    {
        return PLAYER_WIN;
    }
    return TIE;
}

int isWin(char board[ROW][COL], int row, int col)
{
    if(isRowWin(board,row) == 1 || isColWin(board,col) == 1 || isDiagonalWin(board) == 1)
    {
        return PLAYER_WIN;
    } 
    else if(isRowWin(board,row) == 2 || isColWin(board,col) == 2 || isDiagonalWin(board) == 2)
    {
        return COMPUTER_WIN;
    }
    else
    {
        return TIE;
    }
}

void menu()
{
    printf("\nWelcome to Connect Three!\n");
    printf("*************************\n");
    printf("*     1:play  2:exit    *\n");
    printf("*************************\n");
}

void playMenu()
{
    int playerResponse = 0;

    do // do...while
    {
        playerResponse = 0;
        menu();
        printf("Input: ");
        scanf("%d",&playerResponse);
        switch(playerResponse)
        {
            case 1:
                break;

            case 2:
                exit(0);

            default:
                printf("\nSorry, I don't understand what you're trying to say\n");
        }
    }
    while (playerResponse != 1 && playerResponse != 2);
}

int gameEndingCheck(char board[ROW][COL])
{
    if(isWin(board,ROW,COL) == 1 || isWin(board,ROW,COL) == 2)
    {
        Sleep(750);
        if(isWin(board,ROW,COL) == 1)
        {
            printf("Player won!\n");
            return 1;
        }
        else
        {
            printf("Computer won!\n");
            return 1;
        }
    }
    else if(isDraw(board,ROW,COL) == 1)
    {
        Sleep(750);
        printf("It's a draw!\n");
        return 1;
    }
}

void game() //shorten down with different functions
{
    playMenu();
    
    char board[ROW][COL];
    int gameOver = 0;
    int rowPosition;
    int colPosition;
    int draw = 0;
    int win = 0;

    Sleep(1000);
    printf("\nGame started! You are O\n");
    Sleep(500);
    initBoard(board,ROW,COL);
    displayBoard(board,ROW,COL);

    while(1)
    {
        rowPosition = -1;
        colPosition = -1;

        while(rowPosition < 1 || rowPosition > 3) //add a caution if the player plays a wrong place
        {
            printf("What row would you like to play your piece? ");
            scanf("%d",&rowPosition);
            if(rowPosition < 1 || rowPosition > 3)
            {
                printf("You can't place a piece there!\n");
            }
        }

        Sleep(500);
        while(colPosition < 1 || colPosition > 3)
        {
            printf("What column would you like to play your piece? ");
            scanf("%d",&colPosition);
            if(rowPosition < 1 || rowPosition > 3)
            {
                printf("You can't place a piece there!\n");
            }
        }

        while(board[rowPosition-1][colPosition-1] == 'O' || board[rowPosition-1][colPosition-1] == 'X') 
        {
            printf("Sorry a piece is already there!\n");
            rowPosition = -1;
            colPosition = -1;
            while(rowPosition < 1 || rowPosition > 3)
            {
                printf("What row would you like to play your piece? ");
                scanf("%d",&rowPosition);
            }

            Sleep(500);
            while(colPosition < 1 || colPosition > 3)
            {
                printf("What column would you like to play your piece? ");
                scanf("%d",&colPosition);
            }
        }
        
        placePiece(board,rowPosition,colPosition,1);
        Sleep(500);
        printf("You played:\n");
        Sleep(750);
        displayBoard(board,ROW,COL);
        if (gameEndingCheck(board) == 1)
        {
            break;
        }
        Sleep(1000);
        printf("Computer played:\n");
        Sleep(750);
        computerPlay(board);
        displayBoard(board,ROW,COL);   
        if (gameEndingCheck(board) == 1)
        {
            break;
        }
    }
    Sleep(750);
    game();
}

void main()
{
    srand(time(NULL));

    game();
}