#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int *arr = new int[10];
    int arr2[9];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 2 * i;
    }
    cout << sizeof(arr) << endl 
         << sizeof(arr2) << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    delete[] arr;

    return 0;
}
