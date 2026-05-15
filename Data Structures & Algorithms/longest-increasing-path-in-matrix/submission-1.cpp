class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), -1));
    memo.resize(matrix.size(), vector<int>(matrix[0].size(), -1));
    int res = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        res = max(res, dfs(i, j, matrix, visited));
      }
    }
    return res;
  }
  int dfs(int i, int j, const vector<vector<int>>& matrix, vector<vector<int>>& visited) {
    if (i >= matrix.size() || j >= matrix[0].size()) {
      return 0;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    if (visited[i][j] != -1) {
      return 0;
    }
    visited[i][j] = 1;
    const int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 1;
    for (const auto& dir : DIRS) {
      int r = i + dir[0];
      int c = j + dir[1];
      if (r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || visited[r][c] != -1) {
        continue;
      }
      if (matrix[r][c] > matrix[i][j]) {
        res = max(1 + dfs(r, c, matrix, visited), res);
        memo[i][j] = res;
      }
    }
    visited[i][j] = -1;
    return memo[i][j] = res;
  }

private:
  vector<vector<int>> memo;



};
