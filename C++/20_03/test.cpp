#include <iostream>
int main(void)
{
    int a, b, c, max;
    std::cin >> a >> b >> c;
    max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    printf("%d", max);
    return 0;
}