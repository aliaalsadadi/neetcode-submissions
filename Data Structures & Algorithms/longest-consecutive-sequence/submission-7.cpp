class Solution {
public:
    int longestConsecutive(vector<int> &nums)   
    {
        if (nums.size() == 0) {return 0;}
        sort(nums.begin(), nums.end());
        int k = 1;
        int longest = 1;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i+1] == nums[i]) {
                continue;
            }
            if (nums[i + 1] != nums[i] + 1)
            {
                longest = max(longest, k);
                k=1;
            }
            else
            {
                k++;
            }
        }
        return max(longest,k);
    }


};
