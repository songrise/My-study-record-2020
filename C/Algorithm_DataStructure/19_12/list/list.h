/*Write in 2019 12 31*/

#include <stdbool.h>
#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
    int num;
    struct node *nextPtr;
} Node;
typedef Node *ptrToNode;
typedef Node *List; //point to first node in a list.

//suppose header.
ptrToNode MakeList(void);
int len(List);
int Find(const List, int toFind);
// ptrToNode FindPrevious(const List, int toLocate);
bool IsEmpty(const List);
bool Append(List, int);
bool delNode(List, int index);
bool printList(List);
bool delList(List);
bool Clear(List);
#endif