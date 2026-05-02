class Solution {
public:
      vector<int> cache;
  int numDecodings(string s) {
    cache.resize(s.size(), -1);
    return dfsDecode(0, s);
  }
  int dfsDecode(int i, const string& s) {
        
    if (i == s.size()) {
      return 1;
    }
    if (s[i] == '0')
      return 0;
       if (cache[i] != -1) {
      return cache[i];
    }
    int res = dfsDecode(i + 1, s);
    if (i < s.size() - 1) {
      if ((s[i] == '1') || (s[i] == '2' && s[i + 1] < '7')) {
        res += dfsDecode(i + 2, s);
      }
    }
    return cache[i] = res;
  }

};
