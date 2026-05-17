class Solution {
public:
  bool isMatch(string s, string p) {
    memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
    return dfs(s, p, 0, 0);
  }
  bool dfs(const string& s, const string& p, int i, int j) {
    if (i >= s.size() && j >= p.size()) {
      return true;
    } else if (j >= p.size()) {
      return false;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    if (j < p.size() - 1 && p[j + 1] == '*') {
      bool first = i < s.size() && (p[j] == s[i] || p[j] == '.');
      return memo[i][j] = dfs(s, p, i, j + 2) || (first && dfs(s, p, i + 1, j));
    } else {
      if (i >= s.size()) {
        return memo[i][j] = false;
      }
      if (p[j] == '.') {
        return memo[i][j] = dfs(s, p, i + 1, j + 1);
      } else {
        if (p[j] != s[i]) {
          return memo[i][j] = false;
        } else {
          return memo[i][j] = dfs(s, p, i + 1, j + 1);
        }
      }
    }
  }





private:
  vector<vector<int>> memo;


};
