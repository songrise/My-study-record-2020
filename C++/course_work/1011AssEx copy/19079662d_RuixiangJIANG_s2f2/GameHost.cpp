#include "TTT.h"
using namespace std;

int get_command()
{
    char command[BUFSIZE]; //string instead of int, to avoid user input non-digit values.
    printf("                     Input code: ");
    cin >> command;
    while ((command[0] != '1' && command[0] != '0') || command[1] != '\0')
    {
        // ask user input again.
        cin.clear();
        cin.sync();
        RED
            msg_box("WRONG COMMAND");
        CLOSE

        cout << "           Try again (Please input 1 or 0): ";
        cin >> command;
    }
    cin.sync();
    return atoi(command);
}

int select_mode()
{
    msg_box("|  Command  |  1: Vs A.I.  | 2: Vs Player ");

    char command[BUFSIZE]; //string instead of int, to avoid user input non-digit values.
    printf("                     Input code: ");

    cin >> command;
    while ((command[0] != '1' && command[0] != '2') || command[1] != '\0')
    {
        // ask user input again.
        cin.clear();
        cin.sync();
        RED
            msg_box("WRONG COMMAND");
        CLOSE

        cout << "           Try again (Please input 1 or 0): ";
        cin >> command;
    }
    cin.sync();
    return atoi(command);
}

void pvp()
{
    GREEN
    msg_box("You selected Player vs Player.", '=');
    CLOSE
    int first_player = roll_dice() <= 3 ? 1 : 2; // if dice <= 3, then it is player1 first
    char dice_notice[BUFSIZE];
    sprintf(dice_notice, " You Rolled %d ! %s first.", first_player, first_player == 1 ? "Player 1" : "Player 2");
    msg_box(dice_notice);

    int board[9] = {0};
    for (int i = 0; i < 9; i++) // max step is 9
    {
        usleep(200000);
        if (i == 0)
        {
            draw_board(board);
        }
        if (get_action(board, first_player))
        {
            draw_board(board);
            char step_notice[BUFSIZE];
            sprintf(step_notice, "This is step %d, there are %d more steps", i + 1, 8 - i);
            msg_box(step_notice);
        }
        else
        {
            printf("Unexpected error!\n");
            exit(-1);
        }

        if (int winner = check_winner(board))
        {
            char win_notice[BUFSIZE];
            sprintf(win_notice, "Player %d win, Congratulations!", winner);
            msg_box(win_notice);
            break;
        }
        else if (i == 8)
        {
            msg_box("Draw");
        }
    }
}

void pve()
{
    GREEN
    msg_box("You selected Player vs Computer.", '=');
    CLOSE
    msg_box("|  Select Difficulty |  0: Easy  | 1: Hard   ");
    int hard_mode = get_command();
    char mode_notice[BUFSIZE];
    sprintf(mode_notice, "You selected %s mode.", hard_mode ? "hard" : "easy");
    GREEN
    msg_box(mode_notice);
    CLOSE
    int first_player = roll_dice() <= 3 ? 1 : 2;
    //in pve mode. 1 is player, 2 is computer.
    char dice_notice[BUFSIZE];
    sprintf(dice_notice, "You Rolled %d ! %s first.", first_player, first_player == 1 ? "You" : "AI");
    msg_box(dice_notice);
    int board[9] = {0};

    for (int i = 0; i < 9; i++) // max step is 9
    {
        usleep(200000);
        // printf("#%d, %d, %d, %d, %d, %d, %d, %d, %d#\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
        if (next_step(board, first_player) == 1) //player's turn
        {
            if (i == 0 && first_player == 1)
            {
                draw_board(board);
            }

            if (get_action(board, first_player)) //user place his piece at this step
            {

                draw_board(board);
                char step_notice[BUFSIZE];
                sprintf(step_notice, "This is step %d, there are %d more steps", i + 1, 8 - i);
                msg_box(step_notice);
            }
            else
            {
                printf("Unexpected error!\n");
                exit(-1);
            }
        }

        else if (next_step(board, first_player) == 2) //Computer's turn
        {

            hard_mode ? hard_comp_move(board, first_player) : easy_comp_move(board, first_player);
            draw_board(board);
            char step_notice[BUFSIZE];
            sprintf(step_notice, "This is step %d, there are %d more steps", i + 1, 8 - i);
            msg_box(step_notice);
        }

        if (int winner = check_winner(board))
        {
            if (winner == 1)
            {
                GREEN
                msg_box("You win, Congratulations!", '=');
                CLOSE
                break;
            }
            else
            {
                RED
                    msg_box("You lost", '=');
                CLOSE
                break;
            }
        }
        else if (i == 8) //winner == 0
        {
            GREEN
            msg_box("Draw", '=');
            CLOSE
        }
    }
}
