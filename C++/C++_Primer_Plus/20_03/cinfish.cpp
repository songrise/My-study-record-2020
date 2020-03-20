//cinfish.cpp
#include <iostream>
const int Max = 5;
int main(int argc, char const *argv[])
{
    using namespace std;

    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max << " fish <q to terminate>.\n";
    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i])
    {
        if (++i < Max)
            cout << "Fish #" << i + 1 << ": ";
    }
    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];
    // report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of " << i << " fish\n";
    cout << "Done.\n";

    return 0;
}
