/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 执行用时 : 4 ms, 在所有 C 提交中击败了 91.52 % 的用户
// 内存消耗 : 6 MB, 在所有 C 提交中击败了 100.00 % 的用户
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *nextPtr, *prev = NULL;
    while (head)
    {
        nextPtr = head->next;
        head->next = prev;
        prev = head;
        head = nextPtr;
    }
    return prev;
}

//recursive ver.
//Global vairables are not allowed in leetcode, however we can *DEFINE ANOTHER FUNCTION* to solve this.
// 执行用时 : 4 ms, 在所有 C 提交中击败了 91.52 % 的用户
// 内存消耗 : 6.1 MB, 在所有 C 提交中击败了 100.00 % 的用户
struct ListNode *recur(struct ListNode *prev, struct ListNode *head)
{
    struct ListNode *nextPtr;
    if (!head)
        return prev;
    else
    {
        nextPtr = head->next;
        head->next = prev;
        prev = head;
        return recur(head, nextPtr);
    }
}

struct ListNode *reverseList(struct ListNode *head)
{
    return recur(NULL, head);
}
