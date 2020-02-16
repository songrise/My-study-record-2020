/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode *Node;
bool hasCycle(Node head)
{
    Node fast, slow;
    fast = slow = head;
    if (!head || !head->next)
        return false;

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast)
            fast = fast->next;

        if (fast == slow)
            break;
    }

    if (fast) // contains loop
    {
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == head)
            return false;
        else
            return true;
    }

    else
        return false;
}