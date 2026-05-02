class Solution {
public:
 vector<vector<int>> res;
  vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<int> cur;
    dfs(0, cur, nums, target, 0);
    return res;
  }

private:
  void dfs(int i, vector<int> &cur, const vector<int> &nums, int target,
           int sum) {
    if (target == sum) {
      res.push_back(cur);
      return;
    }
    if (i >= nums.size() || sum > target) {
      return;
    }
    cur.push_back(nums[i]);
    dfs(i, cur, nums, target, sum + nums[i]);
    cur.pop_back();
    dfs(i + 1, cur, nums, target, sum);
  }

};
