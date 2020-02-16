#include <stdio.h>

typedef struct student
{
    char id[10];
    char name[20];
    int s1;
    int s2;
    int s3;
} Student;

void input(Student *, int);
void print(Student *, int);

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    Student class[N];
    input(class, N);
    print(class, N);
    return 0;
}

void input(Student *class, int N)
{

    for (int i = 0; i <= N - 1; i++)
    {
        //也要加取址符&， 因为struct.member 是变量而非指针。
        scanf("%s", &class[i].id);
        scanf("%s", &class[i].name);
        scanf("%d", &class[i].s1);
        scanf("%d", &class[i].s2);
        scanf("%d", &class[i].s3);
    }
}

void print(Student *class, int N)
{
    for (int i = 0; i <= N - 1; i++)
    {
        printf("%s,", class[i].id);
        printf("%s,", class[i].name);
        printf("%d,", class[i].s1);
        printf("%d,", class[i].s2);
        printf("%d\n", class[i].s3);
    }
}