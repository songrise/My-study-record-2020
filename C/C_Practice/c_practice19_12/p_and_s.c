#include <stdio.h>
int main(void)
{
    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
    //mesg 和 copy 是存储在两个不同位置，指向同一位置的指针。
    //所以字符串本身并没有副本，而是其创建了其引用的副本。
    return 0;
}