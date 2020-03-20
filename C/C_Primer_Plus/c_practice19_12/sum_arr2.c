#include <stdio.h>
#define SIZE 10
int sump(int *start, int *end);
int main(void)
{
    int marbles[] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sump(marbles, marbles + SIZE);
    //实际上marbles = SIZE是第十一个元素的第一位地址（并不存在11个）
    //c保证此地址指针仍然是有效的，这使得可以用while循环读取到最后一个元素
    //marbles 是数组名， 也是一个指针变量
    printf("The total number of marbles is %ld. \n", answer);
    printf("The size of marbles is %zd bytes.\n", sizeof(marbles));

    return 0;
}

int sump(int *start, int *end)
{
    int total = 0;

    while (start < end)
    {
        total += *start;
        //indirect operator,对地址来翻译
        start++;
        //start++ 加的不是一而是一个单位长度（对于本array而言
        //即是说访问下一个数组元素的首位地址。
    }

    return total;
}
