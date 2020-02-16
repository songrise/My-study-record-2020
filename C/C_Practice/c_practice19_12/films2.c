#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    //创建链表
    puts("ENter first movie title:");
    while (s_gets(input, TSIZE) && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else
        {

            prev->next = current;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating (0-10):");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (Empty line to stop");
        prev = current; //current已经记录完, 在此时便成为prev。
    }
    //显示链表
    if (head == NULL)
        printf("no data entered");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current) //知道current不是NULL
    {
        printf("movie: %s Rating: %d.\n", current->title, current->rating);
        current = current->next; //指向链表下一项
    }

    current = head;
    while (current)
    {
        current = head;
        head = current->next;
        free(current);
    }
    printf("Bye!");

    return 0;
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