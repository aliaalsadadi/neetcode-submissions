class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maxP = max(piles)
        res = maxP
        l, r = 1, res
        while l <= r:
            k = l + (r-l) // 2
            hours = 0
            for p in piles:
                hours += math.ceil(p / k)
            if hours <= h:
                res = min(res, k)
                r = k-1
            else:
                l = k+1
        return res
        