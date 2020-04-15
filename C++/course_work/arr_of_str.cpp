#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // List of 5 names and each has a maximum 10 characters
    char nameList[5][11];
    // Ask for name input
    for (int i = 0; i < 5; i++)
    {
        cout << "Please enter name " << i + 1 << ": ";
        cin.getline(nameList[i], 11, '\n');
        // This segment of code discards extra characters entered
        if (cin.fail())
        {
            cin.clear(); //清除cin 的标识符
            cin.sync();
        }
    }
    for (size_t i = 0; i < 5; i++)
    {
        printf("\n%s", nameList[i]);
    }
}