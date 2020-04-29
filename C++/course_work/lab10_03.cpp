#include <iostream>
#include <cstring>

#define MAXLEN 51
void rotate(char *charArray, int *sizeOfArray);
using namespace std;

int main(int argc, char const *argv[])
{
    char inputStr[MAXLEN];

    cout << "Enter your string: ";
    cin >> inputStr;
    int len = strlen(inputStr);
    cout << endl
         << inputStr;

    for (size_t i = 0; i < len - 1; i++)
    {
        rotate(inputStr, &len);
        cout << endl
             << inputStr;
    }

    return 0;
}

void rotate(char *charArray, int *sizeOfArray)
{
    //space complexity O(n)
    char *temp = new char[*sizeOfArray];
    strncpy(temp, charArray, (*sizeOfArray) - 1);
    *charArray = *(charArray + ((*sizeOfArray) - 1));
    strncpy(charArray + 1, temp, (*sizeOfArray) - 1);
    delete[] temp;
}