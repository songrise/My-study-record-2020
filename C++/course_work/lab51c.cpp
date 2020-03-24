/* 
I put excepting handing code in the caller's code
Since exceptions such as divide by zero should be 
checked before computation.
If I put it in function, Then it will duplicate in 
each fuction. If I put it in caller, It only needs
once.


*/
double RootQuedEquL(double a, double b, double c);
double RootQuedEquS(double a, double b, double c);

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
        cout << "\nRepeated root: x = " << RootQuedEquL(a, b, c);
    }
    else // delta > 0
    {

        cout << "\nTwo real roots x = " << RootQuedEquL(a, b, c) << " or " << RootQuedEquS(a, b, c);
    }

    return 0;
}

double RootQuedEquL(double a, double b, double c)
{
    double ans1, ans2, delta;
    delta = b * b - 4 * a * c;
    ans1 = (-b + sqrt(delta)) / (2 * a);
    ans2 = (-b - sqrt(delta)) / (2 * a);
    return ans1 < ans2 ? ans2 : ans1;
}

double RootQuedEquS(double a, double b, double c)
{
    double ans1, ans2, delta;
    delta = b * b - 4 * a * c;
    ans1 = (-b + sqrt(delta)) / (2 * a);
    ans2 = (-b - sqrt(delta)) / (2 * a);
    return ans1 > ans2 ? ans2 : ans1;
}