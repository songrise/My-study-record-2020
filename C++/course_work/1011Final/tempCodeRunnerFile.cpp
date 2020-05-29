#include <iostream>
using namespace std;

double max(double arr[], int size)
{
    double maxNum = *arr; // init maxNum to be the first elem of arr
    for (int i = 1; i < size; i++)
    {
        if (*(arr++) > maxNum) //pointer arithmetic
            maxNum = *arr;
    }
    return maxNum;
}

double min(double arr[], int size)
{
    double minNum = *arr; // init maxNum to be the first elem of arr
    for (int i = 1; i < size; i++)
    {
        if (*(arr++) < minNum) //pointer arithmetic
            minNum = *arr;
    }
    return minNum;
}
int main()
{
    double data[] = {1, 2, 3, 4, 5};

    cout << "max: " << max(data, 5) << endl;

    cout << "min: " << min(data, 5) << endl;

    return 0;
}