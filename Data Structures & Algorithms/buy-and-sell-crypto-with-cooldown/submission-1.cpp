class Solution {
public:
  int maxProfit(vector<int>& prices) {
    memo.resize(prices.size(), vector<int>(2, -1));
    return dfs(0, prices, false);
  }
  int dfs(int i, const vector<int>& prices, bool buying) {
    if (i >= prices.size()) {
      return 0;
    }
    if (memo[i][buying] != -1) {
      return memo[i][buying];
    }
    if (buying) {
      return memo[i][buying] = max(dfs(i + 1, prices, true), dfs(i + 2, prices, false) + prices[i]);
    } else {
      return memo[i][buying] = max(dfs(i + 1, prices, true) - prices[i], dfs(i + 1, prices, false));
    }
  }

private:
  vector<vector<int>> memo;

};
