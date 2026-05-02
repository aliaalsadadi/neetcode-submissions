class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            for j in range(i+1,len(heights)):
                height = min(heights[i], heights[j])

                width = j - i

                area = height * width
                
                if area > max_area:
                    max_area = area
        return max_area