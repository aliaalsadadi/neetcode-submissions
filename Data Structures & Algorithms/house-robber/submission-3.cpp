class Solution {
public:
vector<int> cache;
        int rob(vector<int> &nums) {
    cache.resize(nums.size(), -1);

    return max(dfsRob(nums, 0), dfsRob(nums, 1));
  }
  int dfsRob(const vector<int> &nums, int i) {
    if (i >= nums.size()) {
      return 0;
    }
    if (cache[i] != -1)
      return cache[i];
    return cache[i] = max(dfsRob(nums, i + 1), nums[i] + dfsRob(nums, i + 2));
  }


};
