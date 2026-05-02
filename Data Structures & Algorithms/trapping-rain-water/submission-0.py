class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        lmax, rmax = height[l], height[r]
        res = 0
        while l < r:
            if lmax < rmax:
                l += 1
                if lmax - height[l] > 0:
                    res += lmax - height[l]

                lmax = max(height[l], lmax)
            else:
                r-=1
                if rmax - height[r] > 0:
                    res += rmax- height[r]
                rmax = max(height[r],rmax)
        return res

