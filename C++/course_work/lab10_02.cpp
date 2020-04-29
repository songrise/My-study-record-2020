#include <iostream>
double average(double *, int);
using namespace std;
int main()
{
    double data[] = {1, 2, 3, 4, 5};
    cout << "average:	" << average(data, 5);
    return 0;
}

double average(double *arr, int arrLen)
{
    double sum = 0;
    for (size_t i = 0; i < arrLen; i++)
    {
        sum += arr[i];
    }
    auto avg = sum / arrLen;
    return avg;
}
