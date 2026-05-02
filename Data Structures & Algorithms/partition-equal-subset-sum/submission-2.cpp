class Solution {
public:
vector<vector<int>> memo;
     bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (const int &num : nums) {
      sum += num;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int target = sum / 2;
    memo.resize(nums.size(), vector<int>(target + 1, -1));
    return dfs(nums, 0, target);
  }
  bool dfs(const vector<int> &nums, int i, int target) {
 
    if (i == nums.size()) {
      return target == 0;
    }
    if (target < 0) {
      return false;
    }
    if (memo[i][target] != -1) {
      return memo[i][target];
    }
    return memo[i][target] =
               dfs(nums, i + 1, target - nums[i]) || dfs(nums, i + 1, target);
  }


};
