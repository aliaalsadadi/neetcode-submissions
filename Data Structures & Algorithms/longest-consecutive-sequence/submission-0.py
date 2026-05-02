class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest = 0

        for num in nums:

            if (num-1) not in numSet:
                length = 0
                while True:
                    if length+num in numSet:
                        length += 1
                    else:
                        break
                longest = max(length,longest)
        return longest
