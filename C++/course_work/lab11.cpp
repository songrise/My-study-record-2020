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
    cout << "Sum is " << sum << endl;
    cout << "Averange is " << avg << endl;
    cout << "Product is " << pro << endl;
    return 0;
}
