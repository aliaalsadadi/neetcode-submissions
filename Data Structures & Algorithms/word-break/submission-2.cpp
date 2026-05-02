class Solution {
public:
     unordered_map<int, bool> memo;
  bool wordBreak(string s, vector<string> &wordDict) {
    memo.clear();
    memo[s.length()] = true;
    return dfsWord(s, wordDict, 0);
  }
  bool dfsWord(const string &s, const vector<string> &wordDict, int i) {
    if (memo.find(i) != memo.end()) {
      return memo[i];
    }
    if (i == s.size()) {
      return memo[i] = true;
    }
    for (const string &w : wordDict) {
      if (i + w.size() <= s.size() && s.substr(i, w.length()) == w) {
        if (dfsWord(s, wordDict, i + w.size())) {
          memo[i] = true;
          return true;
        }
      }
    }
    memo[i] = false;
    return false;
  }


};
