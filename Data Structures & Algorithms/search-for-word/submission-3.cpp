class Solution {
public:
int ROWS, COLS;
set<pair<int,int>> path;
   bool exist(vector<vector<char>> &board, string word) {
    ROWS = board.size();
    COLS = board[0].size();
    path.clear();
    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        if (dfs(board, word, 0, r, c)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(const vector<vector<char>> &board, string word, int i, int r,
           int c) {
    if (i == word.size()) {
      return true;
    }
    if (r >= ROWS || c >= COLS || r < 0 || c < 0 || word[i] != board[r][c] ||
        path.count({r, c})) {
      return false;
    }
    path.insert({r, c});
    bool res = dfs(board, word, i + 1, r - 1, c) ||
               dfs(board, word, i + 1, r + 1, c) ||
               dfs(board, word, i + 1, r, c + 1) ||
               dfs(board, word, i + 1, r, c - 1);
    path.erase({r, c});
    return res;
  }


};
