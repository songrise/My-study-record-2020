#include <iostream>
#define SENTINEL 999
using namespace std;
int main(int argc, char const *argv[])
{
    double sum = 0;
    int total = 0, inputNum = 0;
    cout << "Enter integers(999 to end):";
    cin >> inputNum;
    while (inputNum != SENTINEL)
    {
        sum += inputNum;
        total++;
        cin >> inputNum;
    }

    if (total == 0)
    {
        cout << endl
             << "No input!";
    }
    else
    {
        cout << "The average is: " << sum / total;
    }

    return 0;
}
