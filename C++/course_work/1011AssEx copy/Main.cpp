#include "TTT.h"
using namespace std;

int main(int argc, char const *argv[])
{
    welcome();
    msg_box("|  Command  |  0: Exit  | 1: New Game");

    while (get_command() == 1)
    {
        int mode = -1;
        switch (mode = select_mode())
        {
        case 1:
            pve();
            break;
        case 2:
            pvp();
            break;
        }
        msg_box("|  Command  |  0: Exit  | 1: New Game");
    }

    return 0;
}