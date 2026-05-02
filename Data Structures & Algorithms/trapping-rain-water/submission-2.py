class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        lmax, rmax = height[l], height[r]
        lmaxes, rmaxes = [0] * len(height), [0] * len(height)
        for i, h in enumerate(height):
                lmax = max(h,lmax)
                lmaxes[i] = lmax
        for i, h in enumerate(reversed(height)):
                rmax = max(h,rmax)
                rmaxes[r-i] = rmax
        res = 0
        for i in range(len(height)):
            minlr = min(lmaxes[i],rmaxes[i])
            if minlr - height[i] > 0:
                res += minlr - height[i]
 
        return res

