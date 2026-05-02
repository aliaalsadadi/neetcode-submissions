class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> pac(n, vector<int>(m, -1));
    vector<vector<int>> atl(n, vector<int>(m, -1));
    for (int r = 0; r < n; r++) {
      dfs(r, 0, heights, pac, heights[r][0]);
      dfs(r, m - 1, heights, atl, heights[r][m - 1]);
    }
    for (int c = 0; c < m; c++) {
      dfs(0, c, heights, pac, heights[0][c]);
      dfs(n - 1, c, heights, atl, heights[n - 1][c]);
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (pac[i][j] == 1 && atl[i][j] == 1)
          res.push_back({i, j});
      }
    }
    return res;
  }

  void dfs(int r, int c, const vector<vector<int>>& heights, vector<vector<int>>& visit, int prevHeight) {
    if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || heights[r][c] < prevHeight ||
        visit[r][c] != -1) {
      return;
    }
    visit[r][c] = 1;
    dfs(r + 1, c, heights, visit, heights[r][c]);
    dfs(r - 1, c, heights, visit, heights[r][c]);
    dfs(r, c + 1, heights, visit, heights[r][c]);
    dfs(r, c - 1, heights, visit, heights[r][c]);
  }

};
