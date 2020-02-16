//compile with BinaryTree.c
#include "BinaryTree.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    puts("creating a tree\n");
    tree T = newTree(8);
    puts("successfully created!\n");
    insert(2, T);
    puts("2 inserted\n");
    insert(4, T);
    puts("4 inserted\n");
    insert(19, T);
    puts("19 inserted\n");
    insert(6, T);
    puts("6 inserted\n");
    insert(3, T);
    puts("3 inserted\n");

    int min = retrieve(findMin(T));
    puts("min found\n");
    printf("The min element is %d\n", min);
    int max = retrieve(findMax(T));
    puts("max found\n");
    printf("The max element is %d\n", max);

    delTree(4, T);
    printf("4 deled\n");
    if (find(3, T) != NULL)
        printf("3 found\n");

    printf("inorder traversal:\n");
    InTraverse(T);

    return 0;
}
