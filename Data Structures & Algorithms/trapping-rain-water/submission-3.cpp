class Solution {
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int leftMax = height[i];
            int rightMax = height[i];
            for (int j = 0; j < i; j++)
            {
                leftMax = max(leftMax, height[j]);
            }
            for (int j = i + 1; j < height.size(); j++)
            {
                rightMax = max(rightMax, height[j]);
            }
            res += min(rightMax, leftMax) - height[i];
        }
        return res;
    }

};
