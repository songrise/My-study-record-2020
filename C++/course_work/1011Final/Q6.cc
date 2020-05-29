#include <iostream>
#include <cctype>
// assuming all needed libraries are included
using namespace std;

//my name is modify fun1
// void modify(int x, double y, char z)
// {
//     printf("Fun1\n");
//     x *= 48 + 10;
//     z = tolower(z);
//     y = 3.1415;
// }

//my name is modify fun2
void modify(int *x, double y, char z)
{
    printf("Fun2\n");

    *x *= 48 + 10;
    z = tolower(z);
    y = 3.1415;
}

// my name is modify fun3
void modify(int &x, double y, char z)
{
    printf("Fun3\n");

    x *= 48 + 10;
    z = tolower(z);
    y = 3.1415;
}

int main()
{
    int num = 69;
    double decimal = 3.06247;
    char m = 'M';
    int *nPtr = &num;
    modify(&num, decimal, m);  // #1 call, which fun?
    modify(num, decimal, m);   // #2 call, which fun?
    modify(*nPtr, decimal, m); // #3 call, which fun?
    cout << num << " " << decimal << " " << m << endl;
    return 0;
}