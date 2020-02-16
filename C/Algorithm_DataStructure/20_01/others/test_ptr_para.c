#include <stdio.h>
void printPtr(int *);

int *returnPtr(int *p)
{
    return p;
}

int main(int argc, char const *argv[])
{
    int *p = 8;
    printf("in caller, the P is at %p\n", &p);
    printPtr(p);
    printf("now in caller, the P is at %p\n", &p);
    if (p == returnPtr(p))
    {
        printf("they are identical");
    }
    return 0;
}
void printPtr(int *P)
{
    printf("In function, the P is at %p\n", &P);
    P = P + 1;
}

//linked list implemetation with minor errors.
//(However the recursion is valid)

bool isValidBST(struct TreeNode *root)
{

    if (!root)
        return true;

    isValidBST(root->left);

    register char T = 0;

    if (root->left)
    {
        if (root->val <= root->left->val)
            T = 0;
        else
            T = 1;
    }
    else
        T = 1;

    if (root->right)
    {
        if (root->val >= root->right->val)
            return false;
    }
    else
        return T &= 1;

    isValidBST(root->right);
    return true;
}
