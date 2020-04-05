#include <iostream>
#define BOTTOMLIMIT 0.0
#define UPPERLIMIT 10.0
using namespace std;

int main(int argc, char const *argv[])
{
    double money = 0.0;
    cout << "Enter your money: ";
    while (cin >> money)
    {

        if (money < BOTTOMLIMIT || money > UPPERLIMIT)
        {
            cout << "Your money should be larger than 0 and smaller than 10!";
            cin.sync();
            cout << "Enter your money: ";
        }
        else
        {
            break;
        }
    }
    //do calculations here
    //convert to cents.
    int cents = money * 100;
    int quarters = cents / 25;
    cents %= 25;

    int dimes = cents / 10;
    cents %= 10;

    int nickels = cents / 5;
    cents %= 5;

    int pennies = cents + 1;

    if (quarters)
    {
        if (quarters == 1)
        {
            cout << quarters << " quarter." << endl;
        }
        else
        {
            cout << quarters << " quarters." << endl;
        }
    }
    if (dimes)
    {
        if (dimes == 1)
        {
            cout << dimes << " dime." << endl;
        }
        else
        {
            cout << dimes << " dimes." << endl;
        }
    }
    if (nickels)
    {
        if (nickels == 1)
        {
            cout << cents << " nickels." << endl;
        }
        else
        {
            cout << cents << " nickels." << endl;
        }
    }
    if (pennies)
    {
        if (pennies == 1)
        {
            cout << pennies << " pennie." << endl;
        }
        else
        {
            cout << pennies << " pennies." << endl;
        }
    }
    return 0;
}
