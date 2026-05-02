class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            for (int j = i; j < temperatures.size(); j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }

};
