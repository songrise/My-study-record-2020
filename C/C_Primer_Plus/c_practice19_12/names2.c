#include <stdio.h>
#include <string.h>
//将结构体传递给函数
#define NLEN 30
struct namect
{
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char *s_gets(char *st, int n);

int main(void)
{
    struct namect person;
    person = getinfo();
    person = makeinfo(person);
    showinfo(person);

    return 0;
}

struct namect getinfo(void)
{
    struct namect temp; //在函数内部声明并初始化一个结构体变量
    printf("Please enter your first name.\n");
    s_gets(temp.fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(temp.lname, NLEN);

    return temp;
    //将上述局部变量返回给主调函数。
    //temp应该是自动存储类型，为何在此函数结尾没被消除？
    //是因为return的是值而非对象？
    //见test_storage_time.c
}

struct namect makeinfo(struct namect info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);

    return info;
}

void showinfo(struct namect info)
{
    printf("%s %s, your name contains %d letters.\n", info.fname, info.lname, info.letters);
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }

        return ret_val;
    }
}