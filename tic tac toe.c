#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i ;
int j ;

char board[3][3];
 

void initBoard() {
    for( i=0;i<3;i++) {
        for( j=0;j<3;j++) {
            board[i][j] = ' ';
        }
    }
}


void printBoard() {
    printf("\n");
    for( i=0;i<3;i++) {
        printf("---|---|---\n");
        for( j=0;j<3;j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("---|---|---\n");
}


int checkWinner(char mark) {
    for( i=0;i<3;i++) {
        if(board[i][0]==mark && board[i][1]==mark && board[i][2]==mark)
            return 1;
        if(board[0][i]==mark && board[1][i]==mark && board[2][i]==mark)
            return 1;
    }

    if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark)
        return 1;
    if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)
        return 1;

    return 0;
}


int isFull() {
    for( i=0;i<3;i++)
        for( j=0;j<3;j++)
            if(board[i][j]==' ')
                return 0;
    return 1;
}


void computerMove() {
    int row, col;
    printf("\nComputer is selecting...\n");

    do {
        row = rand()%3;
        col = rand()%3;
    } while(board[row][col] != ' ');

    board[row][col] = 'O';
}

int main() {

    int row, col;
    srand(time(0));

    initBoard();

    while(1) {

        printBoard();

        
        printf("\nEnter row and column to be inputted as X\n");
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);

        if(row<0 || row>2 || col<0 || col>2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = 'X';

        if(checkWinner('X')) {
            printBoard();
            printf("\n?? You Win!\n");
            break;
        }

        if(isFull()) {
            printBoard();
            printf("\nIt's a Draw!\n");
            break;
        }

       
        computerMove();

        if(checkWinner('O')) {
            printBoard();
            printf("\n?? Computer Wins!\n");
            break;
        }

        if(isFull()) {
            printBoard();
            printf("\nIt's a Draw!\n");
            break;
        }
    }

    return 0;
}
