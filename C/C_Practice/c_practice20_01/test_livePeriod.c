#include <stdio.h>
#include <stdlib.h>

char *gen();
char *gen2();

int main(int argc, char const *argv[])
{
    char *arr = gen();
    char *Marr = gen2();

    printf("%c", arr);
    printf("%c", Marr);
    free(Marr);
    return 0;
}

char *gen()
{
    char arr[] = {'T', 'E', 'S', 'T'};
    //warning: function returns address of local variable
    //arr是自动存储类型，具有块生存周期，该指针在离开此函数后被自动释放。
    return arr;
}

char *gen2()
{
    char *arr = malloc(sizeof(char) * 4);
    arr[0] = 'T';
    arr[1] = 'E';
    arr[2] = 'S';
    arr[3] = 'T';
    return arr;
}