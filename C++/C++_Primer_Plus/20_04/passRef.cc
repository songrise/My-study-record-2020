#include <iostream>
using namespace std;

void test(int &);
int main(int argc, char const *argv[])
{
    int temp = 9;
    test(temp);
    cout << temp << endl;
    test(temp);
    test(temp);
    test(temp);

    return 0;
}

void test(int &t)
{
    cout << t << endl;
    t += 3;
}