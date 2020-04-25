#include <iostream>
#include <string>
#include <iomanip>

#define MAXITEMS 100
#define MAXOIS 40

void welcome();
int get_command(void);
void get_OIS(char *arr, int arrLen);
void food_menu();
int get_order();
void set_check(int *packed, int *ordered, int orderedLen);
void check_out(char *ois, int *packed, int packed_len);

using namespace std;

int main(int argc, char const *argv[])
{
    welcome();
    cout << "Command:\n0: exit the system\n1: start ordering\n";
    while (get_command() == 1)
    {
        int ordered[MAXITEMS];
        int packed[MAXITEMS];
        char ois[MAXOIS];
        get_OIS(ois, MAXOIS);
        food_menu();

        int i = 0;

        do
        {
            ordered[i] = get_order();
            cout << "Command\n0: check out\n1: continue this order\n";
        } while (get_command() == 1);

        cout << "Order finished\n";
        set_check(packed, ordered, i + 1);
        check_out(ois, packed, 2);
        cout << "next costumer?\n0: exit the system\n1: start ordering\n";
    }
    cout << "Bye!\n";
}

void welcome()
{
    cout << "Hello!\n\n";
}

int get_command()
{

    int command = -1;
    cin >> command;
    while (command != 1 && command != 0)
    {
        cin.sync();
        cout << "WRONG COMMAND (please enter anagin)\n";
        cin >> command;
    }
    cin.sync();
    return command;
}

void get_OIS(char *oisArr, int arrLen)
{
    cout << "Enter ois: ";
    cin >> oisArr;
}

void food_menu(void)
{
    cout << "Food menu for testing,";
}

int get_order()
{
    int food_NO;
    cin >> food_NO;
    // while (/* condition */)
    {
        //TODO check legability
    }

    return food_NO;
}

void set_check(int *packed, int *ordered, int orderedLen)
{
    for (size_t i = 0; i < orderedLen; i++)
    {
        //TODO check if it is set
        //TODO if it is, put it into packed arr
    }
}

void check_out(char *ois, int *packed, int packedLen)
{
    cout << "Hi! " << ois << endl;
    cout << "Items that you ordered:";
    for (size_t i = 0; i < packedLen; i++)
    {
        //TODO print
    }
}
