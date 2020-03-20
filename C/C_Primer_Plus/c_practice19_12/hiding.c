#include <stdio.h>

int main(void)
{
    int x = 30;

    printf("x in outer block: %d at %p\n", x, &x);
    {
        int x = 77;
        printf("x in inner block: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    while (x++ < 33) //使用的是9行的x
    {
        int x = 100;//只有在块中重新定义并初始化才会（暂时）覆盖原x
        //所以没有第15行， 17行将递加第五行的x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    
    return 0;
}
