/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (!l1)
    {
        return l2;
    }
    else if (!l2)
    {
        return l1;
    }
    else
    {
        if (l1->val <= l2->val)
        {
            struct ListNode *next = l1->next;
            l1->next = l2;
            l2->next = next;
            return mergeTwoLists(l1->next, l2->next);
        }
        else
        {
            struct ListNode *next = l2->next;
            l2->next = l1;
            l1->next = next;
            return mergeTwoLists(l1->next, l2->next);
        }
    }
}
