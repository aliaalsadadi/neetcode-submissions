class Solution {
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq = {};
        for (auto &num : nums)
        {
            freq[num]++;
        }
        vector<pair<int, int>> arr;
        for (const auto &f : freq)
        {
            arr.push_back({f.second, f.first});
        }
        sort(arr.rbegin(), arr.rend());
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i].second);
        }
        return res;
    }

};