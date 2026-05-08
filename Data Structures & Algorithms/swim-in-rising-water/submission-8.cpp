class Solution {
public:
        int swimInWater(vector<vector<int>>& grid) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    int n = grid.size();
    pq.push({grid[0][0], 0, 0});
    const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visit(n, vector<bool>(n, false));
    while (!pq.empty()) {
      auto [timeSofar, r, c] = pq.top();
      pq.pop();
      
      if (r == n - 1 && c == n - 1) {
        return timeSofar;
      }
      if (visit[r][c]) continue;
      visit[r][c] = true;
      for (const auto& dir : dirs) {
        int row = r + dir[0];
        int col = c + dir[1];
        if (row < 0 || row >= n || col < 0 || col >= n || visit[row][col])
          continue;
        pq.push({max(timeSofar, grid[row][col]), row, col});
        
      }
    }
    return n * n;
  }


};