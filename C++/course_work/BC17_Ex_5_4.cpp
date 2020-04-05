#include <iostream>
#include <cctype>
#define MAXLEN 1001
using namespace std;
int main(int argc, char const *argv[])
{
    char str[MAXLEN]; //1000+1 for '\0'
    cout << "Input your string: ";

    cin.getline(str, MAXLEN);

    int i = 0;
    int char_count = 0;
    while (str[i++] != '\0')
    {
        if (isalpha(str[i]))
        {
            char_count++;
        }
    }
    cout << "There are " << char_count << " characters.\n";

    //in fact I shouldn't use isaplha again, I should have save the char judged in first loop.
    for (; i >= 0; i--)
    {
        if (isalpha(str[i]))
        {
            cout << str[i];
        }
    }

    return 0;
}
