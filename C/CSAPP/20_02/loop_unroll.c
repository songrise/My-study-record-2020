#include <stdio.h>
#include <time.h>

clock_t start, end;
double duration;
int main(int argc, char const *argv[])
{
    start = clock();

    //end of code segment
    end = clock();
    duration = end - start;
    printf("\nTime eclipsed :%f", duration);
    getchar();
    return 0;
}