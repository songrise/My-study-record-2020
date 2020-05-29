#include <iostream>
using namespace std;

int main()

{
    int a[3][3] = {{0, 0}, {1, 1}, {2, 2}};
    int b;

    b = a[1][2] + a[2][2] + *(*a);
    cout << b;
    return 0;
}