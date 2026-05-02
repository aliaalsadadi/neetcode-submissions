class Solution {
public:
vector<int> memo;
  int coinChange(vector<int> &coins, int amount) {
      int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;
    for (int a=1;a<amount+1;a++ ){
      for (int c : coins) {
        if (a-c >= 0) {
          dp[a] = min(dp[a], 1+dp[a-c]);
        }
      }
    }
    if (dp[amount] == amount+1) { return -1;}
    return dp[amount];
  }



};
