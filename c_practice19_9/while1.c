#include <stdio.h>
int main(void)
{
    const int times=10;
    int count = 1;
    while (count<times)
    {
      printf("It is %4.d time we do it\n",count);
      count=count+1;
    }
    return 0;
}
