class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    string dots(n, '.');
    vector<string> board(n, dots);
    backtrack(res, board, 0);
    return res;
  }
  void backtrack(vector<vector<string>>& res, vector<string> board, int count) {
    if (count == board.size()) {
      res.push_back(board);
      return;
    }

    for (int j = 0; j < board.size(); j++) {
      if (check(count, j, board)) {
        board[count][j] = 'Q';
        backtrack(res, board, count + 1);
        board[count][j] = '.';
      }
    }
  }
  bool check(int r, int c, vector<string>& board) {
    const int DIRS[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    for (int i = 0; i < board.size(); i++) {
      if (board[r][i] == 'Q' || board[i][c] == 'Q') {
        return false;
      }
      for (const auto& dir : DIRS) {
        int newR = r + dir[0] * i;
        int newC = c + dir[1] * i;
        if (newR >= 0 && newC >= 0 && newR < board.size() && newC < board.size() && board[newR][newC] == 'Q') {

          return false;
        }
      }
    }
    return true;
  }



};
