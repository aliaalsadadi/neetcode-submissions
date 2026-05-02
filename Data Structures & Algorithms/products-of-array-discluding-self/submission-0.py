class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * (len(nums))
        prefix = 1
        for i,num in enumerate(nums):
            res[i] = prefix
            prefix *= num
        print(res)
        postfix = 1
        for i,num in enumerate(reversed(nums)):
            res[len(nums)-1-i] *= postfix
            postfix *= num

        return res