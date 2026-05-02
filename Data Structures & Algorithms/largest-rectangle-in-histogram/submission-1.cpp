class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = heights[0];
        for (int i = 0; i < heights.size(); i++)
        {
            int l = i-1;
            int r = i+1;
            while (l >= 0 && heights[l] >= heights[i])
            {
                l--;
            }
            while (r < heights.size() && heights[r] >= heights[i])
            {
                r++;
            }
            cout << r << ",";
            cout << l << "\n";
            maxArea = max(maxArea, heights[i] * (r - l-1));
        }
        return maxArea;
    }

};
