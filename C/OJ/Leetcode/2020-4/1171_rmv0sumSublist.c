/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeZeroSumSublists(struct ListNode *head)
{
    struct ListNode *headCopy = head, *iter = head;
    int sum;
    for (; iter; iter = iter->next)
    {
        sum = 0;
        struct ListNode *here = iter;
        while (here)
        {
            sum += here->val;
            if (sum == 0)
            {
                if (iter == headCopy)
                {
                    iter = here;
                    headCopy = here;
                }
                else
                {
                    iter->next = here->next; //del
                }
            }
            here = here->next;
        }
    }

    return headCopy;
}