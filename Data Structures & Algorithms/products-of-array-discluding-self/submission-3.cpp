class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        if (nums.size() < 1)
        {
            return vector<int>(0);
        }
        int prod = 1;
        int zerocount = 0;
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());
        prefix[0] = 1;
        postfix[nums.size() - 1] = 1;
        int n = (int)nums.size();
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i-1];
            postfix[n - i - 1] = postfix[n - i] * nums[n - i];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = postfix[i] * prefix[i];
        }
        return res;
    }

};
