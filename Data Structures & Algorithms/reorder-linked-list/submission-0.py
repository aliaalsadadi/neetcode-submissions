# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        if not head or not head.next:
            return  # No need to reorder if the list is empty or has only one element

        # Step 1: Use a list to store the nodes of the linked list
        arr = []
        temp = head
        while temp:
            arr.append(temp)
            temp = temp.next

        # Step 2: Reorder the list using two pointers
        left, right = 0, len(arr) - 1
        while left < right:
            arr[left].next = arr[right]  # Point the left node to the right node
            left += 1
            if left == right:
                break
            arr[right].next = arr[left]  # Point the right node to the next left node
            right -= 1

        # Step 3: Set the next of the last node to None
        arr[left].next = None
