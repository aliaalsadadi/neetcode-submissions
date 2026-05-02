"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        temp = head
        oldtoCopy = {}
        while temp:
            oldtoCopy[temp] = Node(temp.val)
            temp = temp.next
        temp = head
        while temp:
            copy = oldtoCopy[temp]
            if temp.next:
                copy.next = oldtoCopy[temp.next]
            if temp.random:
                copy.random = oldtoCopy[temp.random]
            temp = temp.next
        return oldtoCopy[head]