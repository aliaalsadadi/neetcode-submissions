class Solution {
public:
     int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (const int &num : numSet)
        {
            if (!numSet.contains(num - 1))
            {
                int k = 1;
                while (numSet.contains(num + k))
                {
                    k++;
                }
                longest = max(longest, k);
            }
        }
        return longest;
    }


};
