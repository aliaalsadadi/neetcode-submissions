class Solution {
public:
      vector<vector<string>> partition(string s) {
    vector<string> parts;
    vector<vector<string>> res;
    dfsPart(s, 0, parts, res);
    return res;
  }
  void dfsPart(string s, int i, vector<string> &parts,
               vector<vector<string>> &res) {
    if (i == s.size()) {
      res.push_back(parts);
      return;
    }
    for (int j = i; j < s.size(); j++) {
      if (isPalindrome(s, i, j)) {
        parts.push_back(s.substr(i, j - i + 1));
        dfsPart(s, j + 1, parts, res);
        parts.pop_back();
      }
    }
  }
    bool isPalindrome(string word, int l, int r) {
    while (l < r) {
      if (word[l] != word[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }


};
