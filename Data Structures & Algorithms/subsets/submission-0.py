class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        subset = []
        def traverse(i):
            if i >= n: 
                res.append(subset.copy())
                return
            subset.append(nums[i])
            traverse(i+1)
            subset.pop()
            traverse(i+1)
        traverse(0)
        return res
