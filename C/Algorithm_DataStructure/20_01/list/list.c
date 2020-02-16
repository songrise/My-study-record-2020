#include "list.h"
#include <stdlib.h>
#include <stdio.h>

ptrToNode MakeList(void)
{
    ptrToNode list = malloc(sizeof(Node));
    if (list == NULL)
    {
        printf("Out of space!");
        exit(0);
    }
    list->num = 0;
    list->nextPtr = NULL;
    return list;
}

int len(List header)
{
    /*header supposed*/
    int len = 0;
    ptrToNode node = header;
    while (node->nextPtr)
    {
        node = node->nextPtr;
        len++;
    }
    return len;
}

int Find(const List list, int toFind)
{
    //return the index;
    ptrToNode node = list->nextPtr;
    int index = 0;
    int length = len(list); //同一作用域函数与变量不可同名。
    while (index <= (length - 1))
    {
        if (node->num == toFind)
            return index;
        index++;
    }
    printf("Not found!");
    return -1;
}

bool IsEmpty(const List list)
{
    return (list->nextPtr == NULL);
}

bool Append(List list, int toAppend)
{
    ptrToNode node = list;
    while (node->nextPtr)
    //traverse until last node;
    {
        node = node->nextPtr;
    }

    ptrToNode New = MakeList();
    New->num = toAppend;
    node->nextPtr = New;
    return 1;
}

bool delNode(List list, int index)
{
    int i = -1;
    ptrToNode node = list;
    ptrToNode prev;
    if (index > (len(list) - 1))
    {
        printf("List out of range!");
        exit(0);
    }

    while (i != index)
    {
        i++;
        node = node->nextPtr;
        if (i == index - 1)
        {
            prev = node;
        }
    }
    prev->nextPtr = node->nextPtr;
    free(node);

    return 1;
}

bool printList(List list)
{
    //header is ommited.
    ptrToNode node = list->nextPtr;
    int index = 0;
    while (node->nextPtr)
    {
        printf("index:[%2d],  number:[%4d].\n", index++, node->num);
        node = node->nextPtr;
    }
    //print the last node since the while loop terminates at last node.
    printf("index:[%2d],  number:[%4d].\n", index++, node->num);

    return 1;
}

bool delList(List list)
{
    ptrToNode node = list;
    ptrToNode prev;
    while (node->nextPtr)
    {
        prev = node;
        node = node->nextPtr;
        free(prev);
    }
    free(node);
    return 1;
}

bool Clear(List list)
{
    ptrToNode node = list;
    while (node->nextPtr)
    {
        node->num = 0;
        node = node->nextPtr;
    }
    node->num = 0;
    return 1;
}
