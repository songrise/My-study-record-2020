#include "TTT.h"
using namespace std;

int roll_dice()
{
    srand(time(0));
    int dice = (rand() % 6) + 1;
    GREEN
    printf("                    Rolling dice");
    for (int i = 0; i < 6; i++)
    {

        printf(".");
        fflush(stdout);
        usleep(200000);
    }
    CLOSE
    printf("\r");

    return dice;
}

void piece(int id)
{
    switch (id)
    {
    case 0:
        WHITE
        printf(" ");
        break;
    case 1:
        BLUE
            printf("X");
        WHITE
        break;
    case 2:
        RED
            printf("O");
        WHITE

        break;

    default:
        printf("Unexpected Error!");
        exit(-1);
    }
}

bool get_action(int *board, int first)
{

    int location;
    bool T = false; //T is used for return the the executive status of this procedure
    while (1)
    {
        cin.clear();
        cin.sync();

        printf("          Player %d Which cell you want to place: ", next_step(board, first));
        cin >> location;

        //Error handlings
        if (location < 1 || location > 9)
        {
            msg_box("Error: Invalid cell");
            continue;
        }
        else if (board[location - 1] != 0) //already occupied
        {
            msg_box("Error: The cell is already occupied!");
            continue;
        }
        else //Valid input!!!
        {
            board[location - 1] = next_step(board, first);
            T = true;
            break;
        }
    }
    return T;
}

int next_step(int *board, int first)
{
    //This fuction determines who is the next player (game sequence)
    int Otimes = 0, Xtimes = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 2)
            Otimes++;
        else if (board[i] == 1)
            Xtimes++;
    }
    if (first == 1)
        return Otimes < Xtimes ? 2 : 1;
    else
        return Xtimes < Otimes ? 1 : 2;
}

int check_winner(int *board)
{
    //0: draw, 1: player1 win, 2: player2 win.
    for (int i = 0; i < 3; i++)
    {
        if (board[i] && (board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]))
            return board[i];
    }

    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] && (board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]))
            return board[i];
    }

    if (board[0] && (board[0] == board[4] && board[4] == board[8]))
        return board[0];
    if (board[2] && (board[2] == board[4] && board[4] == board[6]))
        return board[2];
    return 0;
}
