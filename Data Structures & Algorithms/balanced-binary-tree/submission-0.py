# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root: return True
        def height(root):
            if not root: return 0
            return 1 + max(height(root.left),height(root.right))
        l = height(root.left)
        r = height(root.right)
        if (abs(r-l)> 1): return False
        else: return self.isBalanced(root.right) and self.isBalanced(root.left) 