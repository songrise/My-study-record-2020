#include <stdio.h>

typedef struct student
{
    char id[10];
    char name[20];
    int s1;
    int s2;
    int s3;
    int total;
} Student;

void input(Student *, int);

int main(int argc, char const *argv[])
{
    int N;
    double avg1, avg2, avg3;
    double sum1 = 0, sum2 = 0, sum3 = 0;
    scanf("%d", &N);
    Student class[N];
    input(class, N);
    for (int i = 0; i <= N - 1; i++)
    {
        sum1 += class[i].s1;
        sum2 += class[i].s2;
        sum3 += class[i].s3;
    }
    avg1 = sum1 / N;
    avg2 = sum2 / N;
    avg3 = sum3 / N;
    printf("%.0f %.0f %.0f\n", avg1, avg2, avg3);

    int max = 0;
    for (int i = 0; i <= N - 1; i++)
    {
        if (class[i].total > class[max].total)
            max = i;
    }

    printf("%s %s %d %d %d", class[max].id, class[max].name,
           class[max].s1, class[max].s2, class[max].s3);

    return 0;
}

void input(Student *class, int N)
{

    for (int i = 0; i <= N - 1; i++)
    {
        scanf("%s", &class[i].id);
        scanf("%s", &class[i].name);
        scanf("%d", &class[i].s1);
        scanf("%d", &class[i].s2);
        scanf("%d", &class[i].s3);
        class[i].total = class[i].s1 + class[i].s2 + class[i].s3;
    }
}
