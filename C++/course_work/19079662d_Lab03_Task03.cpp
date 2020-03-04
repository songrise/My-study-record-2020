/* 
Two limits
1. No error handling. 
users can input anything for the value of a,b,c
this may lead to unexpected errors

2. a,b,c can only hold integer value;
this is because I declared them to be int
This can be solved by  declaring them to be double


*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    double delta, ans1, ans2;
    cout << "Please enter a: ";
    cin >> a;
    cout << "Please enter b: ";
    cin >> b;
    cout << "Please enter c: ";
    cin >> c;

    if (!a) //error handling
    {
        cout << "a cannot be zero!";
        exit(-1);
    }

    delta = b * b - 4 * a * c;
    cout.setf(ios::showpoint);
    cout.precision(3);
    if (delta < 0)
        cout << "No real root";
    else if (delta == 0)
    {
        ans1 = (-b + sqrt(delta)) / (2 * a);
        cout << "\nRepeated root: x = " << ans1;
    }
    else // delta > 0
    {
        ans1 = (-b + sqrt(delta)) / (2 * a);
        ans2 = (-b - sqrt(delta)) / (2 * a);
        cout << "\nTwo real roots x = " << ans1 << " or " << ans2;
    }

    return 0;
}
