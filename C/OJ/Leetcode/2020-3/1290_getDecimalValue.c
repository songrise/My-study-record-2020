

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//recursive version, this sholude be right.
#include <math.h>
int level = 0;
int getDecimalValue(struct ListNode *head)
{
    if (!head)
        return 0;
    else
    {
        return getDecimalValue(head->next) + (head->val) * pow(2, level++);
    }
}
// 执行用时 : 4 ms, 在所有 C 提交中击败了 61.99 % 的用户
// 内存消耗 : 5.3 MB, 在所有 C 提交中击败了 100.00 % 的用户
int getDecimalValue2(struct ListNode *head)
{
    int num = 0;
    while (head)
    {
        num <<= 1;
        num += head->val;
        head = head->next;
    }
    return num;
}
