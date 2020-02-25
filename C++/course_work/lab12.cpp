#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int salary;
    double future_salary;
    cout << "What is your salary? ";
    cin >> salary;
    future_salary = salary * pow(1.05, 10);
    cout << "After 10 years , your salary is: " << future_salary;
    return 0;
}
