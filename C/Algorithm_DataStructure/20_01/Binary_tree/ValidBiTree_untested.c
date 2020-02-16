/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST(struct TreeNode *root)
{
    int len = sizeof(root);
    struct TreeNode *arr[len + 1];

    for (int i = 1; i < len + 2; i++)
        arr[i] = root[i - 1];

    for (int i = 1; i < len / 2; i++)
    {
        if (arr[2 * i])
            if (arr[i]->val < arr[2 * i]->val)
                return false;
        if (arr[2 * i + 1])
            if (arr[i]->val > arr[2 * i + 1]->val)
                return false;
    }
}
