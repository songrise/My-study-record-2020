#include <stdio.h>
int main(void)
{
    printf("%s,%p,%c\n","We", "are", *"speace farers");
    //字符数组也是数组，因此其数组名（此时是字符串的内容本身）也是其首元素对应的地址

    return 0;
}