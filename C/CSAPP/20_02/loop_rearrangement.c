#include <stdio.h>
#include <time.h>

clock_t start, end;
double duration;
int main(int argc, char const *argv[])
{
    start = clock();
    //code segment
    double ans = 1;
    int i;
    //2x1a loop unroll
    for (i = 1; i <= 0x000fffffe; i = i + 2)
    {
        // This should be (in theroy) 2 times faster.
        // ans = 2 * i + 1 + ans;
        ans = i + ans;
        ans = i + 1 + ans;
    }

    for (; i < 0xffffff; i++)
    {
        ans += i;
    }
    printf("ans = %f\n", ans);
    //end of code segment
    end = clock();
    duration = end - start;
    printf("\nTime eclipsed :%f\n", duration);
    getchar();
    return 0;
}
