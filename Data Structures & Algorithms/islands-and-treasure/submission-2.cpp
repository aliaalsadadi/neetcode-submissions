class Solution {
public:
  int rows, cols;
  vector<vector<int>> seen;
  int runId = 0;

  void islandsAndTreasure(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    seen.assign(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == INT_MAX) {
          runId++;
          int best = INT_MAX;
          dfs(grid, i, j, 0, best);
          grid[i][j] = best;
        }
      }
    }
  }

  void dfs(const vector<vector<int>>& grid, int i, int j, int dist, int& best) {
    if (i < 0 || j < 0 || i >= rows || j >= cols) {
      return;
    }

    if (grid[i][j] == -1) {
      return;
    }

    if (seen[i][j] == runId) {
      return;
    }

    if (dist >= best) {
      return;
    }

    if (grid[i][j] == 0) {
      best = dist;
      return;
    }

    seen[i][j] = runId;

    dfs(grid, i + 1, j, dist + 1, best);
    dfs(grid, i - 1, j, dist + 1, best);
    dfs(grid, i, j + 1, dist + 1, best);
    dfs(grid, i, j - 1, dist + 1, best);

    seen[i][j] = 0; // backtrack
  }
};