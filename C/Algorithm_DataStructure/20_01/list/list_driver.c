#include "list.h"
#include <stdio.h>

List swapAtIndex(List, int index);
List reverse(List); //Non-recursive implementation.
ptrToNode recurFind(List list, int tofind);

int main(int argc, char const *argv[])
{
    ptrToNode theList = MakeList();
    if (IsEmpty(theList))
    {
        printf("Empty list\n");
    }
    Append(theList, 7);
    Append(theList, 9);
    Append(theList, 14);
    printList(theList);
    printf("index of number 7 is %d\n", Find(theList, 7));
    printf("the number after 7 is %d\n", ((recurFind(theList, 7)->nextPtr->num)));
    printf("The length of list is %d\n", len(theList));
    printList(theList);
    printf("Now swap 1 and 2\n");
    theList = swapAtIndex(theList, 1);
    printList(theList);
    printf("now reverse the list");
    theList = reverse(theList);
    printList(theList);

    delList(theList);
    return 0;
}

List swapAtIndex(List L, int index)
{
    ptrToNode prev, next;
    ptrToNode N = L->nextPtr; //be cautious of the header.
    int i = 0;
    int length = len(L);
    while (i < index)
    {
        if (i == index - 1)
            prev = N;
        N = N->nextPtr;
        i++;
    }

    if (N && N->nextPtr)
    {
        next = N->nextPtr;
        prev->nextPtr = next;
        N->nextPtr = next->nextPtr;
        next->nextPtr = N;
    }
    return L;
}

List reverse(List L)
{
    /*write in 2020/1/5, Non-recursive, O(n) time complexity required*/
    ptrToNode header = L, N = L->nextPtr;
    int size = len(L);
    int Larr[size];
    //scan
    for (int i = 0; i < size && N; i++)
    {
        Larr[i] = N->num;
        N = N->nextPtr;
    }
    N = L->nextPtr;

    for (int i = 0; i < size && N; i++)
    {
        N->num = Larr[size - i - 1];
        N = N->nextPtr;
    }

    return L;
}

ptrToNode recurFind(List L, int tofind)
{
    if (L->num == tofind)
        return L;
    else if (!L)
        return NULL;
    else
        return recurFind(L->nextPtr, tofind);
}