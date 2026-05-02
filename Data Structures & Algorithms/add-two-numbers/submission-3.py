# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        cur1 = l1
        cur2 = l2
        num1 = 0
        num2 = 0
        while cur1:
            num1 *= 10
            num1 += cur1.val
            cur1 = cur1.next
        while cur2:
            num2 *= 10
            num2 += cur2.val
            cur2 = cur2.next
        total = int(str(num1)[::-1])+int(str(num2)[::-1])
        if total == 0:
            return ListNode(0)
        print(total)
        res = ListNode(0)
        prev = res
        while total > 0:
            digit = total % 10
            total //= 10
            print(digit)
            # Create a new node with the current digit and link it to the previous node
            prev.next = ListNode(digit)
            prev = prev.next
        return res.next