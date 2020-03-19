#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    double prices[5] = {123, 4532, 45, 2345, 3};
    for (double x : prices)
        cout << x << endl;
    return 0;
}
