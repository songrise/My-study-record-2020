#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <cctype>

#define MAXITEMS 100
#define MAXOIS 40
#define FOODNUM 16
#define NAMELEN 40
#define CODELEN 3

void welcome();
int get_command(void);
void get_OIS(char *arr, int arrLen);
void food_menu();
int get_order();
int *set_pack(int *ordered, int orderedLen, int *packedLen);
bool packable(int foodIndex);
void check_out(char *ois, int *packed, int packed_len);

using namespace std;
struct FoodStruct
{
    char item_code[CODELEN];
    char name[NAMELEN];
    double price;
};

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

int main(int argc, char const *argv[])
{
    welcome();
    cout << "Command:\n0: exit the system\n1: start ordering\n";
    while (get_command() == 1)
    {
        int ordered[MAXITEMS]; //shop cart
        int *packed;           //shop cart after packing. this arr will be newed in set_pack().
        int packed_len = 0;    //length of packed array.
        char ois[MAXOIS];
        get_OIS(ois, MAXOIS);
        food_menu();

        int ordered_index = 0;

        do
        {
            ordered[ordered_index++] = get_order();
            cout << "Command\n0: check out\n1: continue this order\n";
        } while (get_command() == 1);

        cout << "Order finished\n";
        packed = set_pack(ordered, ordered_index, &packed_len);
        check_out(ois, packed, packed_len);
        cout << "next costumer?\n0: exit the system\n1: start ordering\n";
        delete[] packed; // free memory allocated in set_pack();
    }
    cout << "Bye!\n";
    return 1;
}

void welcome()
{
    cout << "Hello!\n\n";
}

int get_command()
{
    string command;
    cin >> command;
    while (command != "1" && command != "0")
    {
        cin.clear();
        cin.sync();
        cout << "WRONG COMMAND (please enter anagin)\n";
        cin >> command;
    }
    cin.sync();
    return stoi(command);
}

void get_OIS(char *oisArr, int arrLen)
{
    cout << "Enter ois: ";
    cin >> oisArr;
}

void food_menu(void)
{
    cout << "=====Food menu=====\n";
    printf("CODE      NAME                           PRICE\n");
    for (size_t i = 0; i < FOODNUM; i++)
    {
        //as you teach c-style string, I will use c style printf.
        // cout << food[i].item_code << "\t\t\t\t" << food[i].name << "\t\t\t\t" << food[i].price << endl;
        printf("%-8s  %-30s    %-.2f\n", food[i].item_code, food[i].name, food[i].price);
    }
}

int get_order()
{
    int food_NO;
    bool success = false;
    cout << "Please input food code: ";
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
            cout << "Invalid code, Please input again: ";
        }
        else
        {
            cout << "You have successfully ordered: " << food[i].name << endl;
        }
    }
    return food_NO;
}

int *set_pack(int *ordered, int orderedLen, int *packedLen)
{
    int packed_index = 0;
    int *packed = new int[orderedLen];

    int ordered_status[FOODNUM] = {0}; //kind of like bucket sort

    for (int i = 0; i < orderedLen; i++)
    {
        //update ordered_status in each iteration.
        int ordered_food_no = ordered[i];
        ordered_status[ordered_food_no]++;

        if (!packable(ordered_food_no))
        {
            //just simply copy it into packed array
            packed[packed_index++] = ordered_food_no;
        }
    }

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

    //put the rest of food into packed array (since they can not form a set)
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

bool packable(int foodIndex)
{
    return foodIndex == 0 || foodIndex == 1 || foodIndex == 2 || foodIndex == 3 || foodIndex == 4 || foodIndex == 5 || foodIndex == 6 || foodIndex == 7 || foodIndex == 9 || foodIndex == 10;
}

void check_out(char *ois, int *packed, int packedLen)
{
    double total_price = 0;
    cout << "Hi! " << ois << endl;
    cout << "Items that you ordered: \n";
    cout << "packedLen in check_out():" << packedLen << endl;
    printf("     CODE  %-30s   %-10s   \n", "FOOD NAME", "PRICE");
    for (size_t i = 0; i < packedLen; i++)
    {
        printf("%-.2d   %-3s   %-30s  $%-.2f\n", i, food[packed[i]].item_code, food[packed[i]].name, food[packed[i]].price);
        total_price += food[packed[i]].price;
    }
    cout << "#########################\n";
    if (total_price > 100)
    {
        cout << "Original Price                             $" << fixed << setprecision(2) << total_price << endl;
        cout << "Disconted Price (95\% discont)              $" << fixed << setprecision(2) << total_price * 0.95 << endl;
    }
    else
        cout << "Total Price                                $" << fixed << setprecision(2) << total_price << endl;
}
