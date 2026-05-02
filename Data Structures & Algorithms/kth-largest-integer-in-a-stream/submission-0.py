import bisect
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.nums = sorted(nums)
        self.k = k
    def add(self, val: int) -> int:
        bisect.insort(self.nums,val)
        if len(self.nums)- self.k <= 0:
            return self.nums[0]
        return self.nums[-self.k]
