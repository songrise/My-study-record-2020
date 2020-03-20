#include <stdio.h>
#define PRAISE "You are extaordinary being"
int main(void)
{
    char name[40];

    printf("Please input your name: ");
    scanf("%s", name); //when encountered with an space, scanf() will terminate,
    printf("Hello %s, %s\n", name, PRAISE);
    return 0;

}
