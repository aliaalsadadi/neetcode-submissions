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
                res = dfs(rem-coins[i])

                if res >= 0:
                    minRes = min(res+1,minRes)
            dp[rem] = -1 if minRes == float('inf') else minRes
            return dp[rem]
        return dfs(amount)
            