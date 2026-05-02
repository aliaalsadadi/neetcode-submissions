class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size();i++)
        {
            int t = temperatures[i];
            while (!st.empty() && st.top().second < t)
            {
                res[st.top().first] = i - st.top().first;
                st.pop();
            }

            st.push({i, t});
        }

        return res;
    }


};
