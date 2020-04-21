#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char *str)
{
    int len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        char str[100];

        cout << "Enter a string: ";
        cin >> str;
        if (str[0] == '0')
            break;
        else
        {
            if (isPalindrome(str))
            {
                cout << "true\n";
            }
            else
            {
                cout << "false\n";
            }
        }
    }
    cout << "Bye!";

    return 0;
}