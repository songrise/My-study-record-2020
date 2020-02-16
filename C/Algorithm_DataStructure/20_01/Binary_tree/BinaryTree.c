#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

tree newTree(int root)
{
    tree new = malloc(sizeof(treeNode));
    if (new == NULL)
    {
        printf("Not enough space!!");
        exit(-1);
    }
    else
    {
        new->left = new->right = NULL;
        new->element = root;
    }
    return new;
}

tree find(int toFind, const tree T)
{
    if (T == NULL)
    {
        printf("Error, not found %d!\n", toFind);
        exit(-1);
    }

    int num = T->element;
    if (toFind > num)
        return find(toFind, T->right);
    else if (toFind < num)
        return find(toFind, T->left);
    else
        return T;
}

tree findMin(const tree T)
{
    if (T->left == NULL)
        return T;

    else
        return findMin(T->left);
}

tree findMax(const tree T)
{
    if (T->right == NULL)
        return T;

    else
        return findMax(T->right);
}

tree makeEmpty(tree T)
{
    if (T)
    {
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
    return NULL;
}

tree insert(int toInsert, tree T)
{
    //create new subtree and insert
    if (T == NULL)
    {
        tree new = newTree(toInsert);
        T = new;
    }
    //locate to the proper place.
    else if (toInsert < T->element)
    {
        T->left = insert(toInsert, T->left);
    }
    else if (toInsert > T->element)
    {
        T->right = insert(toInsert, T->right);
    }

    return T;
}

tree delTree(int toDel, tree T)
{
    if (T == NULL)
    {
        printf("the tree to delete is not found!");
        exit(-1);
    }
    else if (toDel < T->element)
    {
        T->left = delTree(toDel, T->left);
    }
    else if (toDel > T->element)
    {
        T->left = delTree(toDel, T->right);
    }
    //found the root
    if (T->left && T->right)
    {
        tree rMinSub = findMin(T->right);
        T->element = rMinSub->element;
        T->right = delTree(T->element, T->right);
    }
    else
    {
        tree temp = T; //复制指针
        if (T->left == NULL)
        {
            T = T->right;
        }
        else if (T->left == NULL)
        {
            T = T->left;
        }
        free(temp);
    }

    return T;
}

int retrieve(tree T)
{
    if (T == NULL)
    {
        printf("empty tree!");
        exit(-1);
    }
    else
        return T->element;
}

void InTraverse(tree T)
{
    if (T == NULL)
        return;
    else
    {
        InTraverse(T->left);
        printf("%d ", T->element);
        InTraverse(T->right);
    }
}