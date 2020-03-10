#include <iostream>
using namespace std;
int main()
{
    int input;
    cout << "Input an integer between 1 and 9999: ";
    cin >> input;
    int temp = input;
    int d = 1;
    while (temp > 9)
    {
        temp /= 10;
        d++;
    }
    cout << input << " can be expressed in " << d << " digits"
         << "\n";
    return 0;
}
