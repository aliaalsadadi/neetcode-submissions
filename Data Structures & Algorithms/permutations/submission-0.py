class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        perm = []
        pick = [False] * len(nums)
        def dfs():
            if len(perm) == len(nums):
                res.append(perm.copy())
                return
            for i,num in enumerate(nums):
                if not pick[i]:
                    perm.append(num)
                    pick[i] = True
                    dfs()
                    perm.pop()
                    pick[i] = False
        dfs()
        return res