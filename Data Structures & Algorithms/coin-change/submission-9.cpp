class Solution {
public:
vector<int> memo;
  int coinChange(vector<int> &coins, int amount) {
    memo.resize(amount+1, -1);
    int res = dfs(coins, amount, 0);
    return res == INT_MAX ? -1 : res;
  }
  int dfs(const vector<int> &coins, int amount, int numCoins) {
 
    if (amount == 0) {
      return 0;
    }

       if (memo[amount] != -1) {
        return memo[amount];
    }
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        if (amount - coins[i] >= 0) {
            int sub = dfs(coins, amount - coins[i], numCoins + 1);
                if (sub != INT_MAX) {
                    res = min(res, sub + 1);
                }
        }
      
    }
    return memo[amount] = res;
  }



};
