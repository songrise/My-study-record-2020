#include "TTT.h"
using namespace std;

void draw_line(char symbol, int width) //draw a horizontal line
{
    for (int i = 0; i < width; i++)
    {
        cout << symbol;
    }
    cout << endl;
}

void draw_embraced(char symbol, const char *string, int option) // print string embraced by given symbol
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
        printf("%c%-78s%c\n", symbol, string, symbol);

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

void msg_box(const char *string, char tb, char lr)
{
    //tb and lr refer tp top bottom and left right
    draw_line(tb, WIDTH);
    draw_embraced(lr, string, CENTERED);
    draw_line(tb, WIDTH);
}

void welcome()
{
    // WHITE_BC
    BLUE
        BOLD

            draw_line('=', WIDTH);
    draw_embraced('|', " _____ _     _____         _____          ", 1);
    draw_embraced('|', "|_   _(_) __|_   _|_ _  __|_   _|__   ___ ", 1);
    draw_embraced('|', "  | | | |/ __|| |/ _` |/ __|| |/ _ \\ / _ \\", 1);
    draw_embraced('|', "  | | | | (__ | | (_| | (__ | | (_) |  __/", 1);
    draw_embraced('|', "  |_| |_|\\___||_|\\__,_|\\___||_|\\___/ \\___|", 1);
    draw_line('=', WIDTH);
    CLOSE
}

void draw_board(int *board)
{
    // WHITE_BC tem
    // BLACK
    BOLD
        draw_line('=', WIDTH);
    draw_embraced('|', " ", 1);
    draw_embraced('|', "-------------", 1);
    draw_embraced('|', "|   |   |   |", 1);
    printf("|                      | ");
    piece(board[0]);
    printf(" | ");
    piece(board[1]);
    printf(" | ");
    piece(board[2]);
    printf(" |                       |\n");
    draw_embraced('|', "| 1 | 2 | 3 |", 1);
    draw_embraced('|', "|---+---+---|", 1);
    draw_embraced('|', "|   |   |   |", 1);
    printf("|                      | ");
    piece(board[3]);
    printf(" | ");
    piece(board[4]);
    printf(" | ");
    piece(board[5]);
    printf(" |                       |\n");
    draw_embraced('|', "| 4 | 5 | 6 |", 1);
    draw_embraced('|', "|---+---+---|", 1);
    draw_embraced('|', "|   |   |   |", 1);
    printf("|                      | ");
    piece(board[6]);
    printf(" | ");
    piece(board[7]);
    printf(" | ");
    piece(board[8]);
    printf(" |                       |\n");
    draw_embraced('|', "| 7 | 8 | 9 |", 1);
    draw_embraced('|', "-------------", 1);
    draw_line('=', WIDTH);
    CLOSE
}
