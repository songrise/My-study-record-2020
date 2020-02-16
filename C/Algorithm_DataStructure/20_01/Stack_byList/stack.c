#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack MakeStack(void)
{
    return MakeList();
}

bool isEmpty(Stack stack)
{
    return IsEmpty(stack);
}

static Element topElement(const Stack stack)
{
    Element thisElement = stack;
    while (thisElement->nextPtr)
    {
        thisElement = thisElement->nextPtr;
    }
    return thisElement;
}

int top(Stack stack)
{
    Element top = topElement(stack);
    return top->num;
}

bool changeTopValues(Stack stack, int newValue)
{
    Element top = topElement(stack);
    int oldValue = top->num;
    top->num = newValue;
    printf("Top value changed from %d to %d.\n", oldValue, newValue);
    return 1;
}

bool push(Stack stack, int ToPush)
{
    Append(stack, ToPush);
    return 1;
}

bool pop(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is already empty!\n");
        return 0;
    }

    Element prev = stack, this, temp;
    this = prev->nextPtr;

    while (this->nextPtr)
    {
        temp = this;
        this = prev->nextPtr;
        prev = temp;
    }

    prev->nextPtr = NULL;
    free(this);
    return 1;
}

int height(Stack stack)
{
    return len(stack);
}
