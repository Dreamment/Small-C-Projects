#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_ROWS 7
#define BOARD_COLUMNS 6
#define FOUR 4

//if you change board size, change switch case in askMovement function and change the printBoard function depends on your situation

void initializeGameBoard (int (*array)[BOARD_ROWS][BOARD_COLUMNS]);
int changePlayer (int player);
void printBoard (int array[][BOARD_COLUMNS], int player, bool isOver);
int askMovement (int player, int array[][BOARD_COLUMNS]);
int changeBoard (int (*array)[BOARD_ROWS][BOARD_COLUMNS], int place, int player);
int isGameOver (int array[][BOARD_COLUMNS],int player);
void printWin (int a);
void printDraw (void);
int askForNewGame ();

int main (){
    int gameBoard[BOARD_ROWS][BOARD_COLUMNS];
    int userResponse;
    int player;

    do{

        initializeGameBoard(gameBoard);
        player=2;

        do{
            player=changePlayer(player);
            printBoard(gameBoard, player, false);

            do{
                userResponse=askMovement(player, gameBoard);
            }while ( changeBoard (gameBoard,userResponse,player) == 0 );

        }while ( isGameOver(gameBoard,player)== 0 );

    }while ( askForNewGame()==1 );
    return true;
}

void initializeGameBoard (int (*array)[BOARD_ROWS][BOARD_COLUMNS]){
    int i;
    int j;
    int number = 1;
    for (i=0;i<BOARD_ROWS;i++){
        for (j=0;j<BOARD_COLUMNS;j++){
            (*array)[i][j] = number;
            number = number + 1;
        }
    }
}

int changePlayer (int player){
    if (player==1){
        return 2;
    }
    else if (player==2){
        return 1;
    }
}

void printBoard (int array[][BOARD_COLUMNS], int player, bool isOver){
    system ("cls");
    printf("Connect Four Game\n");
    printf("Player 1 = X\n");
    printf("Player 2 = O\n");
    if (isOver == false){
        printf("\nPlayer %d turn (%c)\n", player, (player == 1) ? 'X' : 'O');
    }
    printf("\n");
    printf("| A | B | C | D | E | F |\n");
    printf("|---|---|---|---|---|---|\n");
    int i = 0;
    int j = 0;
    //PLAYER 1 = X = -1
    //PLAYER 2 = O = -2
    for (i=0;i<BOARD_ROWS;i++){
        for (j=0;j<BOARD_COLUMNS;j++){
            if (array[i][j]==-1){
                printf("| X ");
            }
            else if (array[i][j]==-2){
                printf("| O ");
            }
            else{
                printf("|   ");
            }
            if (j==BOARD_COLUMNS-1){
                printf("|\n");
            }
        }
        printf("|---|---|---|---|---|---|\n");
    }
}

int askMovement (int player, int array[][BOARD_COLUMNS]){
    int control = 6;
    char answer;
    if (player == 1)
        printf("Player %d turn. Select a column to put X at the bottom: ", player);
    else if (player == 2)
        printf("Player %d turn. Select a column to put O at the bottom: ", player);
    while (scanf("%c", &answer) != 1)
    {
        printf("Invalid input. Try again:");
    }
    fflush(stdin);
    loop:
    switch (answer) {
        case 'A':
        case 'a':
            control = 0;
            break;
        case 'B':
        case 'b':
            control = 1;
            break;
        case 'C':
        case 'c':
            control = 2;
            break;
        case 'D':
        case 'd':
            control = 3;
            break;
        case 'E':
        case 'e':
            control = 4;
            break;
        case 'F':
        case 'f':
            control = 5;
            break;
        default:
            control = 6;
            printf("Invalid input. Try again:");
    }
    if (control == 6) {
        while (scanf("%c", &answer) != 1)
        {
            printf("Invalid input. Try again:");
        }
        fflush(stdin);
        goto loop;
    }
    for (int i = BOARD_ROWS-1; i >= 0; i--) {
        if (array[i][control] > 0) {
            return array[i][control];
        }
    }
    printf("Column is full. Try again:");
    scanf(" %c", &answer);
    fflush(stdin);
    goto loop;
}

int changeBoard (int (*array)[BOARD_ROWS][BOARD_COLUMNS], int place, int player){
    int i;
    int j;
    for (i=0;i<BOARD_ROWS;i++){
        for (j=0;j<BOARD_COLUMNS;j++){
            if ((*array)[i][j]==place){
                if (player==1){
                    (*array)[i][j]=-1;
                }
                else if (player==2){
                    (*array)[i][j]=-2;
                }
                return 1;
            }
        }
    }
    return 0;
}

int isGameOver (int array[][BOARD_COLUMNS],int player){
    int control = 0;
    if (player == 1)
        control = -1;
    else if (player == 2)
        control = -2;
    bool win = false;
    /*
        3 ways to win
        1. 4 in a row
        2. 4 in a column
        3. 4 in a diagonal
    */

    //control rows

    for (int i = 0; i < BOARD_ROWS; ++i) {
        int check = 0;
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            if (array[i][j] == control) {
                check++;
                if (check == FOUR) {
                    win = true;
                    break;
                }
            }
            else {
                check = 0;
            }
        }
        if (win) {
            break;
        }
    }

    //control columns

    for (int i = 0; i < BOARD_COLUMNS; ++i) {
        int check = 0;
        for (int j = 0; j < BOARD_ROWS; ++j) {
            if (array[j][i] == control) {
                check++;
                if (check == FOUR) {
                    win = true;
                    break;
                }
            }
            else {
                check = 0;
            }
        }
        if (win) {
            break;
        }
    }

    //control diagonals

    for (int i = 0; i < BOARD_ROWS; ++i) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            if (array[i][j] == control) {
                int check = 1;
                int k = 1;

                //control diagonal through right bottom
                while (i + k < BOARD_ROWS && j + k < BOARD_COLUMNS && array[i + k][j + k] == control) {
                    check++;
                    k++;
                }
                if (check == FOUR) {
                    win = true;
                    break;
                }
                check = 1;
                k = 1;

                //control diagonal through left top
                while (i - k >= 0 && j - k >= 0 && array[i - k][j - k] == control) {
                    check++;
                    k++;
                }
                if (check == FOUR) {
                    win = true;
                    break;
                }

                //control diagonal through left bottom
                check = 1;
                k = 1;
                while (i + k < BOARD_ROWS && j - k >= 0 && array[i + k][j - k] == control) {
                    check++;
                    k++;
                }
                if (check == FOUR) {
                    win = true;
                    break;
                }
                check = 1;
                k = 1;

                //control diagonal through right top
                while (i - k >= 0 && j + k < BOARD_COLUMNS && array[i - k][j + k] == control) {
                    check++;
                    k++;
                }
                if (check == FOUR) {
                    win = true;
                    break;
                }
            }
        }
        if (win) {
            break;
        }
    }

    if (win) {
        printWin(player);
    }

    bool isDraw = true;
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLUMNS; ++j) {
            if (array[i][j] > 0) {
                isDraw = false;
            }
        }
    }

    if (isDraw) {
        printBoard(array, player, true);
        printDraw();
        return -1;
    }
    else if (win){
        printBoard(array, player, true);
        printWin(player);
        return 1;
    }
    else
        return 0;
}

void printWin (int player){
    printf("\n\nPlayer %d wins!\n", player);
}

void printDraw (){
    printf("\n\nDraw!\n");
}

int askForNewGame (){
    char answer;
    printf("Do you want to play again? (Y/N): ");
    ask:
    while (scanf("%c", &answer) != 1)
    {
        printf("Invalid input. Try again:");
    }
    fflush(stdin);
    switch (answer) {
        case 'Y':
        case 'y':
            return 1;
        case 'N':
        case 'n':
            return 0;
        default:
            printf("Invalid input. Try again:");
            goto ask;
    }
}