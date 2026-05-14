class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    memo.resize(nums.size()+1, vector<int>(2 * totalSum + 1, -1));
    return dfs(nums, target, totalSum, 0, 0);
  }
  int dfs(const vector<int>& nums, const int& target, int totalSum, int i, int curSum) {
    if (memo[i][curSum + totalSum] != -1) {
      return memo[i][curSum+ totalSum];
    }
    if (i == nums.size()) {
      return memo[i][curSum + totalSum] = curSum == target;
    }
    return memo[i][curSum+totalSum] = dfs(nums, target, totalSum, i + 1, curSum + nums[i]) +
                             dfs(nums, target, totalSum, i + 1, curSum - nums[i]);
  }

private:
  vector<vector<int>> memo;



};
