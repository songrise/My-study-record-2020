#include <stdio.h>
#define SIZE 10
int sum(int *, int );
//函数原型可以没有变量名
int main(void)
{
    int marbles[] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld. \n", answer);
    printf("The size of marbles is %zd bytes.\n", sizeof(marbles));

    return 0;
}

int sum(int *ar, int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes/\n", sizeof(ar));
    //ar 是一个指针变量，指向数组（第一位）的地址，而非数组本身。
    //因此sizeof ar 是指针变量的长度。
    //ar[0] 就是这个指针（？）

        return total;
}
