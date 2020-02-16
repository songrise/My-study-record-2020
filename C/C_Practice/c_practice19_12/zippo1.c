#include <stdio.h>

int main(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};

    printf(" &zippo = %p\n", &zippo);
    //？？array名这个指针和array存在一个地址上？？
    printf(" zippo = %p, zippo +1 =%p\n", zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0]+1 = %p\n", zippo[0], zippo[0] + 1);
    printf("*zippo = %p, *zippo + 1 =%p\n", *zippo, *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf(" *zippo[0] = %d\n", *zippo[0]);
    //zippo[0]是一个array，array名是其首元素第一位的地址，因此对其解引用得到zippo[0]这个数组的第一个元素2
    printf(" **zippo = %d\n", **zippo);
    //解引用两次等同于上面。因为*zippo == zippo[0]
    printf(" zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*zippo+2)+1=%d\n", *(*(zippo+2)+1));

    return 0;
}