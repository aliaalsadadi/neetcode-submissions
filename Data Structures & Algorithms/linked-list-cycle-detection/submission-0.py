# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        temp = head
        visited = set()
        while temp.next != None:
            visited.add(temp.val)
            temp = temp.next
            if temp.val in visited:
                return True
        return False
        