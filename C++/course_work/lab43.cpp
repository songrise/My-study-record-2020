#include <iostream>
using namespace std;
int main()
{
    int rows;
    char theChar;
    cout << "How many rows? ";
    cin >> rows;
    cout << "What characters? ";
    cin >> theChar;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << theChar;
        cout << '\n';
    }

    return 0;
}
