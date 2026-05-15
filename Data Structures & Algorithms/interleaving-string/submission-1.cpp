class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    memo.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    return dfs(s1, s2, s3, 0, 0);
  }
  bool dfs(const string s1, const string s2, const string s3, int i, int j) {
    if (i == s1.size() && j == s2.size() && i + j == s3.size()) {
      return true;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    bool res = false;
    if (s1[i] == s3[i + j]) {
      res |= dfs(s1, s2, s3, i + 1, j);
      memo[i][j] |= res;
    }
    if (s2[j] == s3[i + j]) {
      res |= dfs(s1, s2, s3, i, j + 1);
      memo[i][j] |= res;
    }
    return memo[i][j] = res;
  }

private:
  vector<vector<int>> memo;

};
