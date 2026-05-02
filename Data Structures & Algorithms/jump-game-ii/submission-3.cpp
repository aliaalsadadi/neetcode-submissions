class Solution {
public:
 
  int jump(vector<int>& nums) {
    int n = nums.size();
    cache.resize(n, -1);
    return dfs(nums, 0);
  }
  int dfs(const vector<int>& nums, int i) {
    if (i >= nums.size() - 1) {
      return 0;
    }
    if (cache[i] != -1) {
      return cache[i];
    }

    int temp = INT_MAX;
    for (int x = i + 1; x <= nums[i] + i && x < nums.size(); x++) {
      int sub = dfs(nums, x);
      if (sub != INT_MAX) {

        temp = min(1 + sub, temp);
      }
    }
    return cache[i] = temp;
  }

private:
  vector<int> cache;



};
