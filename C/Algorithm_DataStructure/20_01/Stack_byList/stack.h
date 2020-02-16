/*Write in 2020.1.1*/
#ifndef STACK_H_
#define STACK_H
#include "list.h"
/*each element contains only an int (the member of structure, defined in list.h)*/
typedef ptrToNode Stack;   //point to the bottom of stack.
typedef ptrToNode Element; // point to an element of a stack.

/*fuction prototype */
Stack MakeStack(void);
bool isEmpty(Stack);
static Element topElement(const Stack); //element is the pointer to a structure.
int top(Stack);
bool changeTopValue(Stack, int newValue);
bool push(Stack, int);
bool pop(Stack);
int height(Stack);

#endif