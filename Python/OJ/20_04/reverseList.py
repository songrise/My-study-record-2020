# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        while head.next != None:
            head = head.next
            next_ = head.next
            head.next = prev
            prev = head
            head = next_
        return head