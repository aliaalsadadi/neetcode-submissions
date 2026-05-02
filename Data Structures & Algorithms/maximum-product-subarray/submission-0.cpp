class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            suffix = nums[n - 1 - i] * (suffix == 0 ? 1 : suffix);
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};