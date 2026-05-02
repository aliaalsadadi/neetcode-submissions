class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = {}
        def dfs(rem):
            if rem == 0:
                return 0
            if rem < 0:
                return -1
            if rem in dp:
                return dp[rem]
            minRes = float('inf')
            for i in range(len(coins)):
                if rem-coins[i] not in dp:
                   dp[rem-coins[i]] = dfs(rem-coins[i])
                res = dp[rem-coins[i]]

                if res >= 0:
                    minRes = min(res+1,minRes)
            
            return minRes if minRes != float('inf') else -1
        return dfs(amount)
            