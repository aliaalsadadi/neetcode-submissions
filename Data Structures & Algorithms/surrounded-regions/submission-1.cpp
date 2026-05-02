class Solution {
public:
      void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
          helperSolve(board, i, j);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == '#') {
          board[i][j] = 'O';
        }
      }
    }
  }
  void helperSolve(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i == board.size() || j == board[0].size() || j < 0 || board[i][j] != 'O') {
      return;
    }
    board[i][j] = '#';
    helperSolve(board, i, j - 1);
    helperSolve(board, i + 1, j);
    helperSolve(board, i - 1, j);
    helperSolve(board, i, j + 1);
  }


};
