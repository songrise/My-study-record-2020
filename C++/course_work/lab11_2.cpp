#include <iostream>
#include <algorithm>
#define ARRSIZE 5
using namespace std;

int main(int argc, char const *argv[])
{
    int num[ARRSIZE] = {0};
    for (size_t i = 0; i < ARRSIZE; i++)
    {
        cout << "Please input positive integer " << i + 1 << ":";
        cin >> num[i];
    }
    sort(num, num + ARRSIZE);

    for (size_t i = 1; i < ARRSIZE; i++)
    {
        if (num[i] - 1 != num[i - 1])
        {
            for (size_t i = 0; i < ARRSIZE; i++)
                cout << num[i] << " ";
            cout << "are not consecutive numbers";
            return 0;
        }
    }
    for (size_t i = 0; i < ARRSIZE; i++)
        cout << num[i] << " ";
    cout << "are consecutive numbers";

    return 0;
}
