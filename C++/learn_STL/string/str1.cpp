#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string test;
    test = "test";
    test.push_back('0');
    cout << test;
    int i = test.find("e");
    cout << endl
         << i;
    cout
        << endl
        << test.length();
    return 0;
}
