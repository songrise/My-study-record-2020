#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
    double frac = 0.5;
    int divTimes = 0;
    cout << setprecision(16) << setiosflags(ios::fixed);
    while (frac > 0.0001)
    {
        cout << frac << endl;
        frac /= 2;
        divTimes++;
    }
    cout << frac << endl;
    cout << endl
         << frac << " is just less than 0.0001\n";
    cout << "It needs " << divTimes << " divisions.";
    return 0;
}
