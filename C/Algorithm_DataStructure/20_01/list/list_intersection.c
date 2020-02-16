/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct Listnode *N;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (headA->next && headB->next) // synchroize
        getIntersectionNode(headA->next, headB->next);
    else if (!headA->next && headB->next)
        getIntersectionNode(headA, headB->next);
    else if (!headB->next && headA->next)
        getIntersectionNode(headA->next, headB);
    else //A and B both reached last element
        return NULL;

    static N target = NULL;

    if (headA == headA->next)
        headB = headB->next;

    if (headB == headB->next)
        headA = headA->next;

    if (headA == headB) // comparision between ptr rather than the val.
    {
        target = headA;
    }

    return target;
}