class Solution {
public:
   int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    memo.resize(nums.size(), vector<int>(nums.size(), -1));
    return dfs(nums, 1, nums.size() - 2);
  }
  int dfs(const vector<int>& nums, int l, int r) {
    if (l > r) {
      return 0;
    }
    if (memo[l][r] != -1) {
      return memo[l][r];
    }
    int temp;
    int maxCoins = 0;
    for (int i = l; i <= r; i++) {
      temp = nums[l - 1] * nums[i] * nums[r + 1];
      temp += dfs(nums, l, i - 1) + dfs(nums, i + 1, r);
      maxCoins = max(maxCoins, temp);
    }
    return memo[l][r] = maxCoins;
  }

private:
  vector<vector<int>> memo;

};
