class Solution {
public:
  string minWindow(string s, string t) {
    if (t.empty()) return "";
    unordered_map<char, int> countT(t.size());
    unordered_map<char, int> window;
    int res[2] = {-1, -1};
    int resLen = INT_MAX;
    for (const char &c : t) {
      countT[c]++;
    }
    int l = 0;
    int have = 0;
    int need = countT.size();
    for (int r = 0; r < s.size(); r++) {
      if (countT.count(s[r])) {
        window[s[r]]++;
        if (window[s[r]] == countT[s[r]]) {
          have++;
        }
      }
      while (have == need) {
        int length = r - l + 1;
        if (length < resLen) {
          resLen = length;
          res[0] = l, res[1] = r;
        }
        if (countT.count(s[l])) {
          window[s[l]]--;
          if (window[s[l]] < countT[s[l]])
            have--;
        }
        l++;
      }
    }

    if (resLen != INT_MAX) {
      int l = res[0], r = res[1];
      return s.substr(l, resLen);
    } else {
      return "";
    }
  }

};
