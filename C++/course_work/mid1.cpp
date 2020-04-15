#include <iostream>

using namespace std;
bool all_the_same(double x, double y, double z); // return true if the arguments are all the same
int main(int argc, char const *argv[])
{
    //get user input
    double x, y, z;
    cout << "input 3 doubles for testing, X=";
    cin >> x;
    cout << "Y=";
    cin >> y;
    cout << "Z=";
    cin >> z;
    //testing
    if (all_the_same(x, y, z))
    {
        cout << "They are all the same";
    }
    else
    {
        cout << "X=" << x << " Y=" << y << " Z=" << z << " They are not all the same";
    }

    return 0;
}

bool all_the_same(double x, double y, double z)
{
    if (x == y && y == z)
    {
        return true;
    }
    else
    {
        return false;
    }
}
