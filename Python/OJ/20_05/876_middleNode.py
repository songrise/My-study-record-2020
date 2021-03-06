# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast, slow = head, head
        while(fast):
            fast = fast.next
            if fast:
                fast = fast.next
            slow = slow.next
        return slow.val

