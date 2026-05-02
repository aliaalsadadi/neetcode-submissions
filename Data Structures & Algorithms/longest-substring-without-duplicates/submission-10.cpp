class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int l = 0;
    unordered_set<char> seen; // a b
    int maxRes = 0; // 0
    for (int r = 0; r < s.length(); r++) { // 0 1
      while (seen.count(s[r])) {
        seen.erase(s[l]);
        l++;
      }
      maxRes = max(maxRes, (r - l+1));
      seen.insert(s[r]);
    }
    return maxRes;
  }



};
