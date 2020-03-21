#include <stdio.h>

void changeAPtr(int *);
int main(int argc, char const *argv[])
{
    int a[3] = {1, 2, 3};
    printf("%p\n", a);
    // a++; bugs here!
    changeAPtr(a);

    printf("%p\n", a); // orignal 'a' stay unchanged after increment Arr in call of changeAPtr();

    return 0;
}
void changeAPtr(int *Arr)
{
    //name of an array is a const ptr(const *), so it cannot be assigned (not modifiabel lvalue)
    printf("%p\n", Arr);
    //now I am trying to modify that ptr
    //This can be done here since pass-by-value, Arr is a copy of 'a' in main()
    Arr++;
    printf("%d\n", *Arr);
    printf("%p\n", Arr);
}
