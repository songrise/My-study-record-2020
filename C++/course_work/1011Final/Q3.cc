#include <iostream>
using namespace std;
void fun1(int &a, int *b)
{
    a = 100;
    *b = a;
    b = &a;
    *b = 101;
    cout << a << "  " << *b << endl;
}
int main()
{

    int a = 10;
    int b = 11;
    fun1(a, &b);
    cout << a << "  " << b;
    return 0;
}