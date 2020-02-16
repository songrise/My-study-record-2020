#include <stdio.h>

int creat_a_var(void);
int main(void)
{
    auto int i;
    i = creat_a_var();
    printf("i=%d\n", i);
    printf("varible i at %p.\n", &i);
    return 0;
}

int creat_a_var(void)
{
    int temp = 1;
    printf("local var temp at %p.\n", &temp);
    return temp;
}
