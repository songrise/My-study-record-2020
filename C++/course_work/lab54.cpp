/*
I believe all cases have been handled, to test this, try following cases:

#
Please enter O or X: f
You can only choose O or X
#

#
Please enter O or X: O
Which cell you want to place: 10
Error: Invalid cell
#

#
Please enter O or X:O
Which cell you want to place: 1
Please enter O or X:X
Which cell you want to place: 1
Error: The cell is already occupied!
#

*/

#include <stdio.h> //provide prototype for printf()
#include <iostream>
#include <stdlib.h> //provide prototype for exit()
#define BOARDTYPE char

using namespace std;

bool getAction(BOARDTYPE *, int);
void drawUpdateTTT(const BOARDTYPE *);
BOARDTYPE nextStep(const BOARDTYPE *);
static char first; //first player is either O or X.

int main(int argc, char const *argv[])
{
    BOARDTYPE boardID[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    BOARDTYPE board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("Here is what the game board looks like the IDs of each cell:\n");
    drawUpdateTTT(boardID);

    for (int i = 0; i < 9; i++)
    {
        if (getAction(board, i + 1))
        {
            drawUpdateTTT(board);
            printf("This is step %d, there are %d more steps\n", i + 1, 8 - i);
        }
        else
        {
            printf("Unexpected error!");
            exit(-1);
        }
    }
    drawUpdateTTT(board);
    printf("The end.");

    return 0;
}

void drawUpdateTTT(const BOARDTYPE *board)
{
    //formatted printf() is easier to use for this task.
    //However, I can use cout to rewrite it if necessary.
    int i;
    for (i = 0; i < 6; i += 3)
    {
        printf(" %c| %c |%c \n", board[i], board[i + 1], board[i + 2]);
        printf("---------\n");
    }
    printf(" %c| %c |%c \n", board[i], board[i + 1], board[i + 2]);
}

bool getAction(BOARDTYPE *board, int turn)
{
    char symbol;

    int location;
    bool T = false; //return status of this funcion
    while (1)
    {
        if (!cin) //flush buffer
        {
            cin.sync();
        }

        printf("Please enter O or X: ");
        cin >> symbol;
        if (symbol != 'O' && symbol != 'X')
        {
            printf("You can only choose O or X\n");
            cin.sync();
            continue;
        }

        else if (turn == 1)
            first = symbol;

        else if (symbol != nextStep(board)) //Wrong player
        {
            printf("Error: it is %c turn\n", nextStep(board));
            continue;
        }

        printf("Which cell you want to place: ");
        cin >> location;

        //Error handlings
        if (location < 1 || location > 9)
        {
            printf("Error: Invalid cell\n");
            continue;
        }
        else if (board[location - 1] != ' ') //selected place is already occupied
        {
            printf("Error: The cell is already occupied!\n");
            continue;
        }
        else //Valid input!!!
        {
            board[location - 1] = symbol;
            T = true;
            break;
        }
    }
    return T;
}

BOARDTYPE nextStep(const BOARDTYPE *board)
{
    //This fuction determines the next symbol to be filled
    int Otimes = 0, Xtimes = 0;

    for (int i = 0; i < 9; i++) //travese all cells
    {
        if (board[i] == 'O')
            Otimes++;
        else if (board[i] == 'X')
            Xtimes++;
    }
    if (first == 'X')
        return Otimes < Xtimes ? 'O' : 'X';
    else
        return Xtimes < Otimes ? 'X' : 'O';
}