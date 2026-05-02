# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def traverse(root,level):
            nonlocal res
            if not root: return
            if (len(res) <= level): res.append([])
            res[level].append(root.val)
            traverse(root.left,level+1)
            traverse(root.right,level+1)
        traverse(root,0)
        result = [level[-1] for level in res]
        return result