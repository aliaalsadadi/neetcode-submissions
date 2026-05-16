class Solution {
public:
  int numDistinct(string s, string t) {
    memo.resize(s.size(), vector<int>(t.size(), -1));
    return dfs(s, t, 0, 0);
  }
  int dfs(const string s, const string t, int i, int j) {
    if (j == t.size()) {
      return 1;
    }
    if (i == s.size() && j < t.size())
      return 0;
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    if (s[i] == t[j]) {
      return memo[i][j] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
    } else {
      return memo[i][j] = dfs(s, t, i + 1, j);
    }
  }
private:
  vector<vector<int>> memo;

};
