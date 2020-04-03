#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[90], temp;
    int i = 0;
    while ((temp = cin.get()) != EOF)
    {
        if (temp != ' ')
        {
            str[i++] = temp;
        }
    }
    str[i] = '\0';
    cout << str;

    return 0;
}