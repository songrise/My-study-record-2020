#include "list.h"
#include <stdio.h>

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
    printf("The length of list is %d\n", len(theList));

    if (Clear(theList))
        printList(theList);
    delList(theList);
    return 0;
}
