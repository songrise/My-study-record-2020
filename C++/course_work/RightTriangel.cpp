#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    // possible overflow issues
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
    {
        printf("%d %d and %d can be three sides of a right triangle.", a, b, c);
    }
    else
    {
        printf("%d %d and %d cannot be three sides of a right triangle.", a, b, c);
    }

    return 0;
}
