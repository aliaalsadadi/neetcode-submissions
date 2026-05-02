class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1' && visited[i][j] == -1) {
          res++;
          traverse(visited, i, j, grid);
        }
      }
    }
    return res;
  }
  void traverse(vector<vector<int>> &visited, int i, int j,
                const vector<vector<char>> &grid) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return;
    }
    if (grid[i][j] == '0' || visited[i][j] == 1) {
      return;
    }
    visited[i][j] = 1;
    traverse(visited, i + 1, j, grid);
    traverse(visited, i - 1, j, grid);
    traverse(visited, i, j + 1, grid);
    traverse(visited, i, j - 1, grid);
  }



};
