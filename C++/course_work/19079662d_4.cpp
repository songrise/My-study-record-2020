/*
Limitation1: the use of global variable "first"
We sholud avoid the use of global variable,however
it turns out that we can save uneccessary parameter
by using this variable.

Limitation2: Case conversion
It seems that sometimes user may type lower case alphas,
for example 'o' rather than 'O'.

I sholud be more considerate to convert the letter 
to upper case for some 'careless' users to promote 
their experience.
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define BOARDTYPE char
using namespace std;

bool getAction(BOARDTYPE *, int);
void draw(BOARDTYPE *);
BOARDTYPE nextStep(BOARDTYPE *);

static char first;

int main(int argc, char const *argv[])
{
    BOARDTYPE boardID[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    BOARDTYPE board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    printf("Here is what the game board looks like the IDs of each cell:\n");
    draw(boardID);

    for (int i = 0; i < 9; i++)
    {
        if (getAction(board, i + 1))
        {
            draw(board);
            printf("\nThis is step %d, there are %d more steps\n", i + 1, 8 - i);
        }
        else
        {
            printf("Unexpected error!\n");
            exit(-1);
        }
    }
    draw(board);
    printf("The end.");

    return 0;
}

void draw(BOARDTYPE *board)
{
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
    bool T = false; //T is used for return the the executive status of this procedure
    while (1)
    {
        if (!cin) //flush buffer
        {
            cin.clear();
            cin.sync();
        }

        printf("Please enter O or X: ");
        cin >> symbol;
        if (symbol != 'O' && symbol != 'X')
        {
            printf("You can only choose O or X\n");
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
        else if (board[location - 1] != ' ') //already occupied
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

BOARDTYPE nextStep(BOARDTYPE *board)
{
    //This fuction determines the next symbol to be filled
    int Otimes = 0, Xtimes = 0;
    for (int i = 0; i < 9; i++)
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