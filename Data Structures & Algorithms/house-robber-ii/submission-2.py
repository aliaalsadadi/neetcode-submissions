class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        nums1 = nums[:n-1]
        dp1 = [-1] *len(nums1)
        nums2 = nums[1:]
        dp2 = [-1] * len(nums2)
        memo = [dp1,dp2]
        print(memo)
        
        def dfs(i, num,ch):
            if i >= len(num):
                return 0
            if memo[ch][i] == -1:
                memo[ch][i] = max(dfs(i+1,num,ch), dfs(i+2,num,ch) + num[i])
            return memo[ch][i]
        return max(dfs(0,nums1,0), dfs(0,nums2,1))