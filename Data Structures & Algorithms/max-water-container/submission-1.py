class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0 , len(heights)-1
        max_area = 0
        while l < r:
            h = min(heights[l],heights[r])
            area = h * (r-l)
            if area > max_area:
                max_area = area
            if h == heights[l]:
                l += 1
            else:
                r -= 1
        return max_area
