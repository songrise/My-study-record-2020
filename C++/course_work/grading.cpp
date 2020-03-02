#include <iostream>

using namespace std;
int main()
{
    int mark;
    cout << "Please enter your mark (0 - 100): ";
    cin >> mark;
    cout << "The grade is: ";
    if (mark >= 90 && mark <= 100)
    {
        cout << "A";
    }
    else if (mark >= 70 && mark <= 89)
    {
        cout << "B";
    }
    else if (mark >= 50 && mark <= 69)
    {
        cout << "C";
    }
    else if (mark >= 40 && mark <= 49)
    {
        cout << "D";
    }
    else if (mark >= 0 && mark <= 39)
    {
        cout << "F";
    }
    cout << endl;
    return 0;
}
