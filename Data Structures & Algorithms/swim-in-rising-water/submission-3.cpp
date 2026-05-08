class Solution {
public:
      int swimInWater(vector<vector<int>>& grid) {
    int minMax = INT_MAX;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
    int minH = grid[0][0];
    int maxH = grid[0][0];
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid.size(); j++) {
        minH = min(grid[i][j], minH);
        maxH = max(grid[i][j], maxH);
      }
    }
    for (int t = minH; t < maxH; t++) {
      if (dfs(grid, 0, 0, t, visited)) {
        return t;
      }
      for (int r = 0; r < visited.size(); r++) {
        fill(visited[r].begin(), visited[r].end(), false);
      }
    }
    return maxH;
  }
  bool dfs(const vector<vector<int>>& grid, int r, int c, int t, vector<vector<bool>>& visited) {
    
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid.size() || visited[r][c] || grid[r][c] > t) {
      return false;
    }
    if (r == grid.size() - 1 && c == grid.size() - 1) {
      return true;
    }
    
    visited[r][c] = true;
    return dfs(grid, r + 1, c, t, visited) || dfs(grid, r, c + 1, t, visited) || dfs(grid, r - 1, c, t, visited) ||
           dfs(grid, r, c - 1, t, visited);
  }

};