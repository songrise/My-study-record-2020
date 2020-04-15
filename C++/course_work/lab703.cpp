#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int freq[6] = {0, 0, 0, 0, 0, 0};
    for (size_t i = 0; i < 10000; i++)
    {
        int temp = rand() % 6 + 1;
        freq[temp - 1] += 1;
    }

    cout << "Face\tFrequency\n";
    for (size_t i = 0; i < 6; i++)
    {
        cout << "  " << i + 1 << "\t" << freq[i] << endl;
    }

    return 0;
}
