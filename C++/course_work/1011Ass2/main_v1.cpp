/*compile under Linux g++*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <time.h>
#include <unistd.h>

using namespace std;

#define WIDTH 60
#define BUFSIZE 256
#define CENTERED 1
#define LEFTALIGNED 0

/*************function prototypes**************/
void welcome(void);
int get_command(void);
int select_mode(void);
void pve();
void pvp();
int roll_dice();
inline char piece(int chessID);
void draw_board(int *board);
bool get_action(int *board, int first);
void AI_step(int *board, int first);
int next_step(int *board, int first);
int check_winner(int *board);

inline void draw_line(char symbol, int width);                              //draw horizontal line
inline void draw_embraced(char symbol, const char *string, int option = 0); // print string embraced by given symbol
inline void msg_box(const char *string, char tb = '-', char lr = '|');
//TODO I shall wrap a msg_box() function

int main(int argc, char const *argv[])
{
    welcome();
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
    }

    return 0;
}

/******FUNCTION PART1 (FRONT-END)******/

void welcome()
{
    cout << "Welcome!\n";
}

int get_command()
{
    msg_box("|  Command  |  0: Exit  | 1: New Game");
    char command[BUFSIZE]; //string instead of int, to avoid user input non-digit values.
    cin >> command;
    while ((command[0] != '1' && command[0] != '0') || command[1] != '\0')
    {
        // ask user input again.
        cin.clear();
        cin.sync();
        msg_box("WRONG COMMAND");

        cout << "           Try again (Please input 1 or 0): ";
        cin >> command;
    }
    cin.sync();
    return atoi(command);
}

int select_mode()
{
    // ! maybe use get_command()
    msg_box("|  Command  |  1: Vs A.I.  | 2: Vs Player");

    char command[BUFSIZE]; //string instead of int, to avoid user input non-digit values.
    cin >> command;
    while ((command[0] != '1' && command[0] != '2') || command[1] != '\0')
    {
        // ask user input again.
        cin.clear();
        cin.sync();
        msg_box("WRONG COMMAND");

        cout << "           Try again (Please input 1 or 0): ";
        cin >> command;
    }
    cin.sync();
    return atoi(command);
}

inline void draw_line(char symbol, int width) //draw a 1horizontal line
{
    for (int i = 0; i < width; i++)
    {
        cout << symbol;
    }
    cout << endl;
}

inline void draw_embraced(char symbol, const char *string, int option) // print string embraced by given symbol
{
    int len = strlen(string);

    if (len >= WIDTH - 2)
    {
        //exceptions.
        cout << "string is too long, program aborted.";
        exit(-1);
    }
    //width is hardcoded to 60 here. Because I don't know how to set it to a macro or a variable inside a formatted string.
    if (option == 0) //left aligned
        printf("%c%-78s%c", symbol, string, symbol);

    else if (option == 1) // center aligned.
    {
        int space = (WIDTH - 2 - len) / 2;
        cout << symbol;
        for (int i = 0; i < space; i++)
        {
            cout << " ";
        }
        cout << string;
        for (int i = 0; i < WIDTH - 2 - len - space; i++)
        {
            cout << " ";
        }
        cout << symbol << endl;
    }
    else
    {
        //exceptions.
        cout << "Illegal option: " << option << endl;
        exit(-1);
    }
}

inline void msg_box(const char *string, char tb, char lr)
{
    //tb and lr refer tp top bottom and left right
    draw_line(tb, WIDTH);
    draw_embraced(lr, string, CENTERED);
    draw_line(tb, WIDTH);
}

/******FUNCTION PART1 (BACK-END)******/
void pvp()
{
    msg_box("You selected Player vs Player.", '=');
    int first_player = roll_dice() <= 3 ? 1 : 2;
    cout << "ID of board.\n";
    printf(" %d| %d |%d \n---------\n %d| %d |%d \n---------\n %d| %d |%d \n", 1, 2, 3, 4, 5, 6, 7, 8, 9);
    int board[9] = {0};
    for (int i = 0; i < 9; i++) // max step is 9
    {
        usleep(200000);
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
    msg_box("You selected Player vs Computer.", '=');
    int first_player = roll_dice() <= 3 ? 1 : 2;
    //in pve mode. 1 is player, 2 is computer.
    cout << "ID of board.\n";
    printf(" %d| %d |%d \n---------\n %d| %d |%d \n---------\n %d| %d |%d \n", 1, 2, 3, 4, 5, 6, 7, 8, 9);
    int board[9] = {0};
    for (int i = 0; i < 9; i++) // max step is 9
    {
        usleep(200000);
        printf("#%d, %d, %d, %d, %d, %d, %d, %d, %d#\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
        if (next_step(board, first_player) == 1) //player's turn
        {
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
        }
        else if (next_step(board, first_player) == 2) //Computer's turn
        {
            AI_step(board, first_player);
            draw_board(board);
            char step_notice[BUFSIZE];
            sprintf(step_notice, "This is step %d, there are %d more steps", i + 1, 8 - i);
            msg_box(step_notice);
        }

        if (int winner = check_winner(board))
        {
            if (winner == 1)
                msg_box("You win, Congratulations!", '=');
            else
                msg_box("You lost", '=');
            break;
        }
        else if (i == 8) //winner == 0
        {
            msg_box("Draw", '=');
        }
    }
}

int roll_dice()
{
    srand(time(0));
    int dice = (rand() % 6) + 1;
    cout << "Rolled " << dice << endl;
    return dice;
}

inline char piece(int id)
{
    switch (id)
    {
    case 0:
        return ' ';
    case 1:
        return 'X';
    case 2:
        return 'O';

    default:
        cout << "Unexpected Error!";
        exit(-1);
    }
}

void draw_board(int *board)
{
    int i;
    for (i = 0; i < 6; i += 3)
    {
        printf(" %c| %c |%c \n", piece(board[i]), piece(board[i + 1]), piece(board[i + 2]));
        printf("---------\n");
    }
    printf(" %c| %c |%c \n", piece(board[i]), piece(board[i + 1]), piece(board[i + 2]));
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

void AI_step(int *board, int first)
{
    int location;
    while (1)
    {
        if (board[4] == 0)
            location = 5;
        else
            location = (rand() % 9) + 1;

        if (location < 1 || location > 9)
        {
            continue;
        }
        else if (board[location - 1] != 0) //already occupied
        {
            continue;
        }
        else //Valid input!!!
        {
            printf("                    Processing");
            for (int i = 0; i < 6; i++)
            {

                printf(".");
                fflush(stdout);
                usleep(150000);
            }
            printf("\r");
            char pos_notice[BUFSIZE];
            sprintf(pos_notice, "AI selected position %d", location);
            msg_box(pos_notice);
            board[location - 1] = next_step(board, first);
            break;
        }
    }
}

int next_step(int *board, int first)
{
    //This fuction determines the next symbol to be filled
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

    if (board[0] && (board[0] == board[4] && board[4] == board[9]))
        return board[0];
    if (board[2] && (board[2] == board[4] && board[4] == board[6]))
        return board[2];
    return 0;
}