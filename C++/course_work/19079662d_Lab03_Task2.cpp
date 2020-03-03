#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c, sum, pro;
    double avg;
    cout << "Input three integers:";
    cin >> a >> b >> c;
    sum = a + b + c;
    avg = (double)sum / 3;
    pro = a * b * c;
    // find min and max
    int min = a, max = a;
    if (b > max)
        max = b;
    else if (b < min)
    {
        min = b;
    }
    if (c > max)
        max = c;
    else if (c < min)
    {
        min = c;
    }

    cout << "Sum is " << sum << endl;
    cout << "Averange is " << avg << endl;
    cout << "Product is " << pro << endl;
    cout << "Smallest is " << min << endl;
    cout << "Largest is " << max << endl;

    return 0;
}
