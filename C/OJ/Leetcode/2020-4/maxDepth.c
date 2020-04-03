/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recur(int *max, int temp, struct TreeNode *root)
{
    if (root->left)
    {
        recur(max, temp + 1, root->left);
    }
    else if (temp > *max)
    {
        *max = temp;
    }
    if (root->right)
    {
        recur(max, temp + 1, root->right);
    }
    else if (temp > *max)
    {
        *max = temp;
    }
}

int maxDepth(struct TreeNode *root)
{

    int max = 1;
    if (!root)
        return 0;
    recur(&max, 1, root);
    return max;
}
