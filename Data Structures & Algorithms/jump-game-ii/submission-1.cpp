class Solution {
public:
 
  int jump(vector<int>& nums) {
    int n = nums.size();
    cache.assign(n, vector<int>(n + 1, -1));
    return dfs(nums, 0, 0);
  }
  int dfs(const vector<int>& nums, int i, int jumps) {
    if (i >= nums.size() - 1) {
      return jumps;
    }
    if (cache[i][jumps] != -1) {
      return cache[i][jumps];
    }

    int temp = INT_MAX;
    for (int x = i + 1; x <= nums[i] + i && x < nums.size(); x++) {
      temp = min(dfs(nums, x, jumps + 1), temp);
    }
    return cache[i][jumps] = temp;
  }

private:
  vector<vector<int>> cache;


};
