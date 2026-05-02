class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    int minute = 0;
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2)
          q.push({i, j});
        if (grid[i][j] == 1)
          fresh++;
      }
    }
    const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    while (!q.empty() && fresh > 0) {
      int curSize = q.size();
      for (int i = 0; i < curSize; i++) {
        auto [r, c] = q.front();
        q.pop();
        grid[r][c] = 2;
        for (int d = 0; d < dirs.size(); d++) {
          int row = r + dirs[d][0];
          int col = c + dirs[d][1];
          if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] == 1 || grid[row][col] != 1) {
            continue;
          }
          fresh--;
          visited[row][col] = 1;

          q.push({row, col});
        }
      }

      minute++;
    }
    return fresh == 0 ? minute : -1;
  }


};
