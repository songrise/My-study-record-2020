#include "ae_task2.h"
using namespace std;

//this function has already integrated to the whole program
//see task2 for more details

void easy_comp_move(int *board, int first)
{
    int location;
    while (1)
    {
        if (board[4] == 0)
            location = 5;
        else
            location = (rand() % 9) + 1; //just random choose a location

        //check the validity of the choosen location
        if (location < 1 || location > 9)
        {
            continue;
        }
        else if (board[location - 1] != 0) //already occupied
        {
            continue;
        }
        else //Valid
        {
            board[location - 1] = next_step(board, first); //update game board
            break;
        }
    }
}
