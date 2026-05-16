class Solution {
public:
  int minDistance(string word1, string word2) {
    memo.resize(word1.size(), vector<int>(word2.size(), -1));
    return dfs(word1, word2, 0, 0);
  }
  int dfs(const string& word1, const string& word2, int i, int j) {
    if (i == word1.size() && j == word2.size()) {
      return 0;
    } else if (i == word1.size() && j < word2.size()) {
      return word2.size() - j;
    } else if (j == word2.size() && i < word1.size()) {
      return word1.size() - i;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    if (word1[i] == word2[j]) {
      return memo[i][j] = dfs(word1, word2, i + 1, j + 1);
    } else {
      int replace = 1 + dfs(word1, word2, i + 1, j + 1);
      int del = 1 + dfs(word1, word2, i + 1, j);
      int insert = 1 + dfs(word1, word2, i, j + 1);
      return memo[i][j] = min(replace, min(del, insert));
    }
  }



private:
  vector<vector<int>> memo;


};
