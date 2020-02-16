#include "stack.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Test for stack\n");
    printf("Creat an new stack\n");
    Stack stack = MakeStack();
    if (isEmpty(stack))
        printf("The stack is now empty.\n");

    puts("now push two value to stack.\n");
    push(stack, 9);
    push(stack, 19);
    printf("push success\n");
    printf("Now the stack top is %d\n", top(stack));
    printf("height of stack is %d\n", height(stack));
    if (pop(stack))
        printf("pop success");
    else
        printf("pop failure.");

    printf("After popping an item, now the top is %d\n", top(stack));
    Clear(stack);

    return 0;
}
