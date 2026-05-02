# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:    
        ancp = []
        ancq = []
        cur = root
        while (cur):
            ancp.append(cur)
            if (cur.val > p.val):
                cur = cur.left
            elif (cur.val < p.val):
                cur = cur.right
            else:
                break
        cur = root
        while (cur):
            ancq.append(cur)
            if (cur.val > q.val):
                cur = cur.left
            elif (cur.val < q.val):
                cur = cur.right
            else:
                break
        i = 0
        lca = None
        while (i < len(ancp) and i < len(ancq) and ancp[i] == ancq[i]):
            lca = ancp[i]
            i += 1
        return lca