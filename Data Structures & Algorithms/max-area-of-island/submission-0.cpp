class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j] == -1 && grid[i][j] == 1) {
          res = max(dfs(grid, i, j, visited), res);
        }
      }
    }
    return res;
  }
  int dfs(const vector<vector<int>> &grid, int i, int j,
          vector<vector<int>> &visited) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == 0)
      return 0;
    if (visited[i][j] == 1) {
      return 0;
    }
    visited[i][j] = 1;
    return 1 + dfs(grid, i + 1, j, visited) + dfs(grid, i - 1, j, visited) +
           dfs(grid, i, j - 1, visited) + dfs(grid, i, j + 1, visited);
  }

};
