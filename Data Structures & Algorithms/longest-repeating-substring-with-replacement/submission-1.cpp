class Solution {
public:
  int characterReplacement(string s, int k) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      unordered_map<char, int> count(26);
      int maxf = 0;
      for (int j = i; j < s.size(); j++) {
        maxf = max(maxf, count[s[j]]++);
        if ((j - i )-maxf <= k) {
          res = max(res, (j - i + 1));
        }
      }
    }
    return res;
  }

};
