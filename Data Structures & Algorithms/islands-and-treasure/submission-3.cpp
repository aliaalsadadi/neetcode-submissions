class Solution {
public:
     void islandsAndTreasure(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          q.push({i, j});
          visited[i][j] = 1;
        }
      }
    }
    int dist = 0;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto& [row, col] = q.front();
        q.pop();

        grid[row][col] = dist;
        for (int d = 0; d < 4; d++) {
          int r = row + dirs[d][0];
          int c = col + dirs[d][1];
          if (r < 0 || c < 0 || r >= n || c >= m || visited[r][c] == 1 || grid[r][c] != INT_MAX) {
            continue;
          }
          visited[r][c] = 1;
          q.push({r, c});
        }
      }
      dist += 1;
    }
  }





};
