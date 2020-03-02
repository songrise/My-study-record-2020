#include <iostream>
using namespace std;
int fact(int a);
int main(int argc, char const *argv[])
{
    int num, ans;
    cout << "Please input a number:";
    cin >> num;
    ans = fact(num);
    cout << " \nThe factorial of " << num << " is " << ans;

    return 0;
}

int fact(int a)
{
    if (a <= 0)
    {
        return 1;
    }

    if (a == 1)
        return 1;
    else
    {
        return a * fact(a - 1);
    }
}