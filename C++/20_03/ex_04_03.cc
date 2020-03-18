#include <iostream>
#include <cstring>
using namespace std;
char *getStr(void);

int main(int argc, char const *argv[])
{
    char full[40] = {0}, *first, *last;
    cout << "Enter your first name: ";
    first = getStr();
    cout << "Enter your last name: ";
    last = getStr();

    strcat(full, first);
    strcat(full, ", ");
    strcat(full, last);
    cout << "Here's the information in a single string : " << full;

    delete[] first;
    delete[] last;

    return 0;
}

char *getStr()
{
    char buffer[80];
    cin >> buffer;
    auto str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    cin.sync();
    return str;
}