#include <stdio.h>
#define LEN 20

struct names
{
    char first[LEN];
    char last[LEN]
};

struct guy
{
    struct names handle;
    char favfood[LEN];
    char jobs[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2] =
        //创建并初始化一个2个元素的数组，其元素的类型是guy。 即两个朋友。
        {
            {{"Ewen", "Villard"}, //初始化嵌套结构
             "grilled salmon",
             "personality coach",
             68112.00},
            {{"Rodney", "Swillbelly"},
             "tripe",
             "tabloid editor",
             432400.00

            }};
    struct guy *him; //创建一个指向 guy（结构）类型的指针。

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);

    him = &fellow[0];
    printf("Pointer #1: %p #2: %p\n", him, him + 1);
    printf("him -> income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);
    him++; //指向下一个结构，即fellow[1]
    printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);

    return 0;
}
