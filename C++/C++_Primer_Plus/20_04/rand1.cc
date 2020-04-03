#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    srand(10311);
    for (size_t i = 0; i < 6; i++)
    {
        cout << i + 1 << "th draw: " << rand() % 6 << endl;
        /* code */
    }

    return 0;
}
