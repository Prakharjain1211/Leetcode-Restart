# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slowptr = fastptr = head

        while fastptr and fastptr.next:
            slowptr = slowptr.next
            fastptr = fastptr.next.next

            if slowptr == fastptr:
                break          
        else:
            return None
        
        while head!=slowptr:
            head,slowptr = head.next,slowptr.next
        return head
