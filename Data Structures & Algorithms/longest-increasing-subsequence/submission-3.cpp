class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
    int dp[nums.size()];
    for (int i = 0; i < nums.size(); i++)
      dp[i] = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int j = i+1; j < nums.size(); j++) {
        if (nums[j] > nums[i]) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
    }
    return *max_element(dp, dp + nums.size());
  }



};
