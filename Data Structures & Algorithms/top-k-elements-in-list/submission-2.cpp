class Solution {
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count = {};
        vector<vector<int>> freq(nums.size()+1);
        for (auto &num : nums)
        {
            count[num]++;
        }
        vector<pair<int, int>> arr;
        for (const auto &f : count)
        {
            freq[f.second].push_back(f.first);
        }
        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--)
        {
            for (int n : freq[i]) {
                res.push_back(n);
            }
            if (res.size() == k) {
                return res;
            }
        }
        return res;
    }

};