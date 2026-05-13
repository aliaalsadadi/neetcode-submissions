class Solution {
public:
    int change(int amount, vector<int>& coins) {
    sort(coins.begin(), coins.end());
    memo.resize(coins.size(), vector<int>(amount + 1, -1));
    return dfs(amount, coins, 0);
  }
  int dfs(int amount, const vector<int>& coins, int i) {
    if (amount == 0) {
      return 1;
    } else if (amount < 0) {
      return 0;
    }

    if (i >= coins.size())
      return 0;
    if (memo[i][amount] != -1) {
      return memo[i][amount];
    }
    int res = 0;
    if (coins[i] <= amount) {
      return memo[i][amount] = dfs(amount - coins[i], coins, i) + dfs(amount, coins, i + 1);
    }
    return 0;
  }

private:
  vector<vector<int>> memo;

};
