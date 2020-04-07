#include <stdio.h>

int main(int argc, char const *argv[])
{
    float temp, max, min;
    scanf("%f", &temp);
    max = temp;
    min = temp;
    while (temp >= 0)
    {
        if (temp > max)
            max = temp;
        else if (temp < min)
        {
            min = temp;
        }
        scanf("%f", &temp);
    }
    printf("max=%f,\nmin=%f.", max, min);
    return 0;
}
