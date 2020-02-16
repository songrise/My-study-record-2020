#include <stdio.h>
void butler(void);
int main(void)/*no fenhao*/

{
    printf("I will summon the butler function. \n");
    butler();
    //butler is always call at here,but it can be defined below.
    printf("Yes some tea . \n");
    return 0;
}

void butler(void)
{
    printf("you rang?.\n");
}

