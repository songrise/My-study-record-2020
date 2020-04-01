#include <iostream>
#define ARRLEN 1000
#define SENTINEL -999
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[ARRLEN] = {0};
    cout << "Enter a sequence of integer (-999 to finish): ";
    int i = 0, sum = 0, temp = 0;
    cin >> temp;
    while (temp != SENTINEL)
    {
        sum += temp;
        arr[i] = temp;
        i++;
        cin >> temp;
    }
    cout
        << (sum / i);
    return 0;
}
