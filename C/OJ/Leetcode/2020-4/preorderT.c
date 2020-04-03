/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *arr = malloc(sizeof(int) * (*returnSize));
    if (!root)
return
else
{
    
}

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
