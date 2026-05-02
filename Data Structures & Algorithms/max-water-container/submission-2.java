class Solution {
    public int maxArea(int[] heights) {
         int l = 0, r = heights.length-1;
         int max = 0;
         while (l < r)
         {
            int h = Math.min(heights[l], heights[r]);
            int area = h * (r-l);
            max = Math.max(max,area);
            if (h == heights[l])
            {
                l += 1;
            } else {
                r -=1;
            }
         }
         return max;
    }
}
