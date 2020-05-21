/*
*By Ruixiang JIANG for COMP1011 assignment 1
*Compile under Linux g++
*/

/***************INCLUDES***************/
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <cctype>
/***********END OF INCLUDES************/

/*************CONSTANTS****************/
#define MAXITEMS 100 //max foods
#define MAXOIS 41    //max length of ois string(including '\0')
#define FOODNUM 16   //total number of foods
#define NAMELEN 40   //max length of a food name
#define CODELEN 3    //max length of a food code
#define WIDTH 60     //length of the horizontal line
/**********END OF CONSTANTS***********/

/********FUNCTION PROTOTYPES*********/
void welcome();
int get_command(void);
void get_OIS(char *arr, int arrLen);
void show_menu(); // draw menu
int get_order();
int *set_pack(int *ordered, int orderedLen, int *packedLen); //detect if user ordered set combos, return packed array.
void check_out(char *ois, int *packed, int packed_len);
/*UI functions*/
inline void draw_line(char symbol, size_t width);                           //draw horizontal line
inline void draw_embraced(char symbol, const char *string, int option = 0); // print string embraced by given symbol
/**********END OF PROTOTYPES*********/

/****************TYPES***************/
struct FoodStruct
{
    char item_code[CODELEN];
    char name[NAMELEN];
    double price;
};
/***********END OF TYPES**************/

/***************GLOBALS***************/
const FoodStruct food[FOODNUM] = {
    {"A1", "Cheese veggie sandwich ", 30},
    {"A2", "Salmon & cheese sandwich", 34},
    {"A3", "Chicken Caesar Sandwich", 32},
    {"B1", "(Quebec homemade) Quiche", 28},
    {"B2", "Bagel with Cream Cheese", 36},
    {"B3", "(East Village Chicken) Pie", 28},
    {"C1", "Coffee", 36},
    {"C2", "Green Tea", 28},
    {"C3", "Hot Chocolate", 28},
    {"C4", "Milk", 26},
    {"C5", "Juice", 26},
    {"S1", "Refreshing Breakfast", 48},
    {"S2", "Best Value Breakfast", 60},
    {"S3", "Veggie Lunch", 50},
    {"S4", "Power Lunch", 90},
    {"S5", "Afternoon Tea Set", 50}

};
/**********END OF GLOBALS**************/

using namespace std;

int main(void)
{
    //Refer to pesudo-code for more clear version of main() function.
    welcome();
    while (get_command() == 1)
    {
        draw_line('-', WIDTH);
        int ordered[MAXITEMS]; //shop cart
        int *packed;           //shop cart after packing. this arr will be newed in set_pack().
        int packed_len = 0;    //length of packed array.
        char ois[MAXOIS];

        get_OIS(ois, MAXOIS);
        cout << endl;
        draw_line('=', WIDTH);
        char hi[MAXOIS + 10] = "Hi, ";
        draw_embraced('|', strncat(hi, ois, MAXOIS), 1);
        show_menu();

        int ordered_index = 0; // index for the "ordered" array.

        do //user start ordering foods
        {
            ordered[ordered_index++] = get_order();
            draw_line('-', WIDTH);
            draw_embraced('|', "  Command:  |  0: Check Out  |  1: Continue this order ", 1);
            draw_line('-', WIDTH);
            cout << "               Please input your command: ";

        } while (get_command() == 1);
        //order finised.
        cout << endl;
        draw_line('=', WIDTH);
        draw_embraced('|', "Order finished", 1);
        draw_line('=', WIDTH);
        //process ordered array.
        packed = set_pack(ordered, ordered_index, &packed_len);
        check_out(ois, packed, packed_len);

        draw_line('-', WIDTH);
        draw_embraced('|', " Next Costumer? | 0: Exit System | 1: Start Ordering ", 1);
        draw_line('-', WIDTH);
        cout << "               Please input your command: ";

        delete[] packed; // free memory allocated in set_pack();
    }

    draw_line('*', WIDTH);
    draw_embraced('*', "System Exited. Good Bye!", 1);
    draw_line('*', WIDTH);

    return 0;
}

/******FUNCTION PART1(SYSTEM IMPLEMENTATION)******/

void welcome()
{
    draw_line('=', WIDTH);
    //draw "723 cafe"
    cout << "|             ____   ___ ____           __                 |\n"
         << "|            |__  |_|_  )__ /  __ __ _ / _|___             |\n"
         << "|              / /___/ / |_ \\ / _/ _` |  _/ -_)            |\n"
         << "|             /_/   /___|___/ \\__\\__,_|_| \\___|            |\n";
    draw_line('=', WIDTH);
    // cout.setf(ios::center);
    draw_embraced(' ', "Welcome to 7-23 Cafe Food Service Order System!", 1);

    draw_line('-', WIDTH);
    draw_embraced('|', "Command:", 1);
    draw_embraced('|', "0: Exit the System", 1);
    draw_embraced('|', "1: Start Ordering", 1);
    draw_line('-', WIDTH);
    cout << "               Please input your command: ";
}

int get_command()
{
    char command[NAMELEN]; //string instead of int, to avoid user input non-digit values.
    cin >> command;
    while ((command[0] != '1' && command[0] != '0') || command[1] != '\0')
    {
        // ask user input again.
        cin.clear();
        cin.sync();

        draw_line('-', WIDTH);
        draw_embraced('|', "WRONG COMMAND", 1);
        draw_line('-', WIDTH);

        cout << "           Try again (Please input 1 or 0): ";
        cin >> command;
    }
    cin.sync();
    return atoi(command);
}

void get_OIS(char *oisArr, int arrLen)
{
    draw_embraced('|', "OIS (Order Identification String)", 1);
    draw_line('-', WIDTH);
    cout << "         Please input your OIS (in one word): ";

    cin >> oisArr;
    cin.clear();
    cin.sync();
}

void show_menu(void)
{
    draw_embraced('|', "MENU", 1);
    draw_line('=', WIDTH);
    printf("|  CODE  |                 NAME                  |  PRICE  |\n");
    draw_line('-', WIDTH);

    for (size_t i = 0; i < FOODNUM; i++)
    {
        printf("|   %s   | %-30s        | $%-.2f  |\n", food[i].item_code, food[i].name, food[i].price);
        if (2 == i || 5 == i || 10 == i)
            draw_line('-', WIDTH);
        if (i > 10)
        {
            //show the set make-up
            switch (i)
            {
            case 11:
                printf("|        |   -%-30s     |         |\n", food[6].name);
                printf("|        |   -%-30s     |         |\n", food[4].name);
                printf("|        |    %-30s     |         |\n", "");
                break;
            case 12:
                printf("|        |   -%-30s     |         |\n", food[9].name);
                printf("|        |   -%-30s     |         |\n", food[2].name);
                printf("|        |   -%-30s     |         |\n", food[4].name);
                printf("|        |    %-30s     |         |\n", "");
                break;
            case 13:
                printf("|        |   -%-30s     |         |\n", food[10].name);
                printf("|        |   -%-30s     |         |\n", food[0].name);
                printf("|        |    %-30s     |         |\n", "");
                break;
            case 14:
                printf("|        |   -%-30s     |         |\n", food[10].name);
                printf("|        |   -%-30s     |         |\n", food[6].name);
                printf("|        |   -%-30s     |         |\n", food[1].name);
                printf("|        |   -%-30s     |         |\n", food[5].name);
                printf("|        |    %-30s     |         |\n", "");
                break;
            case 15:
                printf("|        |   -%-30s     |         |\n", "Coffee or Tea");
                printf("|        |   -%-30s     |         |\n", "Quiche or Pie");
                break;

            default:
                break;
            }
        }
    }
    draw_line('=', WIDTH);
}

int get_order()
{
    int food_NO;
    bool success = false; //got order or not?
    cout << "                Please input food code: ";
    char input_code[NAMELEN]; //longer than need. To avoid buffer overflow.

    while (!success)
    {
        cin.clear();
        cin.sync();
        cin >> input_code;

        int i;
        for (i = 0; i < FOODNUM; i++)
        {
            if (strncmp(input_code, food[i].item_code, NAMELEN) == 0)
            {
                food_NO = i;
                success = true;
                break; //exit for loop.
            }
        }

        if (!success)
        {
            cin.clear();
            cin.sync();
            draw_line('-', WIDTH);
            draw_embraced('|', "INVALID CODE", 1);
            draw_line('-', WIDTH);
            cout << "               Please input again: ";
        }
        else
        {
            char you_have_ordered[2 * MAXOIS] = "Successfully ordered: ";
            draw_line('=', WIDTH);
            draw_embraced('|', strncat(you_have_ordered, food[i].name, 2 * MAXOIS), 1);
            draw_line('=', WIDTH);
        }
    }
    cin.sync();
    return food_NO;
}

int *set_pack(int *ordered, int orderedLen, int *packedLen)
{
    int packed_index = 0;
    int *packed = new int[orderedLen];

    int ordered_status[FOODNUM] = {0}; //a "bucket"

    for (int i = 0; i < orderedLen; i++)
    {
        //update ordered_status array in each iteration.
        int ordered_food_no = ordered[i];
        ordered_status[ordered_food_no]++;
    }

    //brute force algorithm to detect set combo.
    while (ordered_status[5])
    {
        //check S1 set
        if (ordered_status[3])
        {
            packed[packed_index++] = 11;
            ordered_status[5] -= 1;
            ordered_status[3] -= 1;
        }
        else
            break;
    }

    while (ordered_status[9])
    {
        //check S2 set
        if (ordered_status[4])
        {
            if (ordered_status[2])
            {
                packed[packed_index++] = 12;
                ordered_status[9] -= 1;
                ordered_status[4] -= 1;
                ordered_status[2] -= 1;
            }
            else
                break;
        }
        else
            break;
    }

    while (ordered_status[10])
    {
        //check S3 set
        if (ordered_status[0])
        {
            packed[packed_index++] = 13;
            ordered_status[10] -= 1;
            ordered_status[0] -= 1;
        }
        else
            break;
    }

    while (ordered_status[10])
    {
        //check S4 set
        if (ordered_status[6])
        {
            if (ordered_status[5])
            {
                if (ordered_status[1])
                {
                    packed[packed_index++] = 14;
                    ordered_status[10] -= 1;
                    ordered_status[6] -= 1;
                    ordered_status[5] -= 1;
                    ordered_status[1] -= 1;
                }
                else
                    break;
            }
            else
                break;
        }
        else
            break;
    }
    while (ordered_status[6])
    {
        //check S5 set
        if (ordered_status[3])
        {
            packed[packed_index++] = 15;
            ordered_status[6] -= 1;
            ordered_status[3] -= 1;
        }

        if (ordered_status[5])
        {
            packed[packed_index++] = 15;
            ordered_status[6] -= 1;
            ordered_status[5] -= 1;
        }
        else
            break;
    }

    while (ordered_status[7])
    {
        //check S5 set
        if (ordered_status[3])
        {
            packed[packed_index++] = 15;
            ordered_status[7] -= 1;
            ordered_status[3] -= 1;
        }

        if (ordered_status[5])
        {
            packed[packed_index++] = 15;
            ordered_status[7] -= 1;
            ordered_status[5] -= 1;
        }
        else
            break;
    }

    //put the rest of food into packed array
    for (size_t i = 0; i < FOODNUM; i++)
    {
        while (ordered_status[i])
        {
            packed[packed_index++] = i;
            ordered_status[i] -= 1;
        }
    }

    *packedLen = packed_index;
    return packed;
}

void check_out(char *ois, int *packed, int packedLen)
{
    double total_price = 0;

    char hi[MAXOIS + 10] = "Hi, ";
    draw_embraced('|', strncat(hi, ois, MAXOIS), 1);
    draw_embraced('|', "Items that you ordered: ", 1);
    draw_line('=', WIDTH);
    printf("|  CODE  |                 NAME                  |  PRICE  |\n");
    draw_line('-', WIDTH);

    for (size_t i = 0; i < packedLen; i++) // draw recipt
    {
        printf("|   %s   | %-30s        | $%-.2f  |\n", food[packed[i]].item_code, food[packed[i]].name, food[packed[i]].price);
        total_price += food[packed[i]].price;
    }
    draw_line('-', WIDTH);

    if (total_price > 100) //discount
    {
        // I used c++ style precision here.
        cout << "|  Original Price                                | $" << fixed << setprecision(2) << total_price << " |" << endl;
        cout << "|  Price after 95 \%discount                      | $" << fixed << setprecision(2) << total_price * 0.95 << " |" << endl;
    }
    else
        cout << "|  Total Price  |                                | $" << fixed << setprecision(2) << total_price << "  |" << endl;

    draw_line('=', WIDTH);
    char bye[MAXOIS + 10] = "Bye,  ";
    draw_embraced('|', strncat(bye, ois, MAXOIS), 1);
    draw_line('=', WIDTH);
    cout << endl;
}

/******FUNCTION PART2 (EXTRA UI IMPLEMENTATION)******/

inline void draw_line(char symbol, size_t width) //draw a 1horizontal line
{
    for (size_t i = 0; i < width; i++)
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
        printf("%c%-58s%c", symbol, string, symbol);

    else if (option == 1) // center aligned.
    {
        int space = (WIDTH - 2 - len) / 2;
        cout << symbol;
        for (size_t i = 0; i < space; i++)
        {
            cout << " ";
        }
        cout << string;
        for (size_t i = 0; i < WIDTH - 2 - len - space; i++)
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
