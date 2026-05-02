class Solution {
public:
    vector<int> memo;
  int lengthOfLIS(vector<int> &nums) {
    memo.resize(nums.size(), -1);
    int maxLIS = 1;
        for (int i = 0; i < nums.size(); i++) {
            maxLIS = max(maxLIS, dfsLIS(nums, i));
        }
        return maxLIS;
  }
  int dfsLIS(const vector<int> &nums, int i) {
    if (memo[i] != -1) {
      return memo[i];
    }

    int LIS = 1;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] > nums[i]) {
        LIS = max(LIS, 1+dfsLIS(nums, j));
      }
    }
    return memo[i] = LIS;
  }


};
