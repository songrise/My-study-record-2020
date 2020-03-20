#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    int carrots;

    cout << "How many carrots do you have?\n";
    cin >> carrots;
    cout << "Here are two more.";
    carrots += 2;
    cout << "now you have " << carrots << " Carrots " << endl;

    return 0;
}