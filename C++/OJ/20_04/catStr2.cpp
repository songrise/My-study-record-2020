//use cstring
#include <iostream>
#include <cstring>
#define BUF 60
using namespace std;
int main()
{
    char a[BUF], b[BUF];
    cin >> a;
    cin >> b;
    strncat(a, b, BUF);
    cout << a;
    return 0;
}