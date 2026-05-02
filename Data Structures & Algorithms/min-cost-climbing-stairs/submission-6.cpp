class Solution {
public:
  vector<int> cache;
  int minCostClimbingStairs(vector<int> &cost) {
    cache.resize(cost.size(), -1);
    return min(dfs(0, cost), dfs(1, cost));
  }
  int dfs(int i, const vector<int> &cost) {
    if (i >= cost.size()) {
      return 0;
    }
    if (cache[i] != -1) {
      return cache[i];
    }
    return cache[i] = cost[i] + min(dfs(i + 1, cost), dfs(i + 2, cost));
  }


};
