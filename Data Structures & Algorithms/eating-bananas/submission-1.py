class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maxP = max(piles)
        for k in range(1, maxP+1):
            hours = 0
            for p in piles:
                hours += math.ceil(p/k)
            if hours <= h:
                return k
        