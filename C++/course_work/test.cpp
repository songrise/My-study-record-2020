#include <iostream>
#include <string>
using namespace std;
// string val()
// {
//     string result = "candy";
//     return;
// }
int main()
{
    string a;
    int i;
    int j;
    for (i = 0; i < 6; i++)
    {
        for (j = 7; j > i; j--)
        {
            cout << "+";
        }
        cout << endl;
    }
}