#include <stdio.h>
int main(void)
{
    int age;
    float assets;
    char pet[30];

    printf("enter your age,assets,and favorite pet.\n");
    scanf("%d %f",&age,&assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n",age,assets,pet);

    return 0;
}