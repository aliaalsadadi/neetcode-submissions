class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxArea = 0;
        stack<pair<int, int>> st; // {i, h}
        for (int i = 0; i < heights.size(); i++)
        {
            int start = i;
            while (!st.empty() && st.top().second > heights[i])
            {
                int height = st.top().second;
                int index = st.top().first;
                maxArea = max(height * (i - index), maxArea);
                start = index;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while (!st.empty())
        {
            const auto &pair = st.top();
            int index = st.top().first;
            int height = st.top().second;
            maxArea = max(maxArea, (height * (static_cast<int>(heights.size()) - index)));
            st.pop();
        }

        return maxArea;
    }


};
