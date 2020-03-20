#include <iostream>
#include <string>
using namespace std;
string getStr(void);
int main(int argc, char const *argv[])
{
    string full, first, last;
    cout << "Enter your first name: ";
    first = getStr();
    cout << "Enter your last name: ";
    last = getStr();
    full = first + ", " + last;
    cout << "Here's the information in a single string : " << full;

    return 0;
}

string getStr()
{
    string inputStr;
    cin >> inputStr;
    cin.sync();
    return inputStr;
}