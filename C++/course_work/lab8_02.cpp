#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    const int SIZE = 1000;
    char str[SIZE];
    cout << "Enter the string: ";
    cin.getline(str, SIZE);
    int len = strlen(str);

    if (islower(str[0]))
    {
        str[0] = toupper(str[0]);
    }
    for (size_t i = 1; i < len; i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }

    }

    cout << "Formatted str: \n";

    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == ',')
        {
            cout << str[i];
            if (str[i + 1] != ' ')
                cout << " ";
            continue;
        }
        if (i > 0)
        {
            if (str[i] == ' ')
            {
                if (str[i - 1] != ' ')
                {
                    cout << str[i];
                    continue;
                }
            }
        }
        cout << str[i];
    }

    return 0;
}
