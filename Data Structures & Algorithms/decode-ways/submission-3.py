class Solution:
    def numDecodings(self, s: str) -> int:
        dp = {}
        def dfs(i):
            if i in dp:
                return dp[i]
            if i>= len(s):
                return 1
            
            if s[i] == '0':
                return 0
            
            res = dfs(i+1)
            if i+1<len(s):            
                if s[i] == '1' or (s[i+1] < '7' and s[i] == '2'):
                    res += dfs(i+2)
            dp[i] = res
            return res
        res = dfs(0)
        print(dp)
        return res

            