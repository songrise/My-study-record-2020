#include <iostream>

using namespace std;
const float HIGHER = 0.9;
const float MEDIUM = 0.8;
const float LOWER = 0.7;

int main()
{

    int a = 12, b = 23;
    float rate;

    // process 1
    switch (a)
    {
    case 1:
    case 2:
    case 3:
        rate = HIGHER;
        break;
    case 4:
    case 5:
    case 6:
        rate = MEDIUM;
        break;
    case 7:
    case 8:
    case 9:
        rate = LOWER;
        break;
    case 10:
    case 11:
    case 12:
        rate = HIGHER;
    }

    // process 2
    if (((a % 3) == 0) && (b >= 21))
    {
        if (rate == HIGHER)
            rate = MEDIUM;
        else if (rate == MEDIUM)
            rate = LOWER;
        else if (rate == LOWER)
            rate = MEDIUM;
        else
            rate = HIGHER;
    }

    // output
    cout << rate;
    return 0;
}