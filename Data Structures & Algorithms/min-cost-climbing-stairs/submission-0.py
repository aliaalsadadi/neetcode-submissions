class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        res = 0
        mem = {}
        def dfs(i):
            if i >= len(cost):
                return 0
            if i+1 not in mem:
                mem[i+1] = dfs(i+1)
            if i+2 not in mem:
                mem[i+2] = dfs(i+2)
            return cost[i] + min(mem[i+1], mem[i+2])
        return min(dfs(0),dfs(1))