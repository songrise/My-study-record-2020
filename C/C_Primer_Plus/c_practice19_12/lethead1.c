//lethead1.c
#include <stdio.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define Place "Megapolis, CA 94904"
#define WIDTH 40

void starbar(void);

int main(void)
{
    starbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", Place);
    starbar();

    return 0;
}

void starbar(void)
{
    int count;

    for (count = 1; count <= WIDTH ; count++)
        putchar('*');  //a bug has been caused by type???? 为什么printf（‘*’） 不行？？？？
    putchar('\n');
}