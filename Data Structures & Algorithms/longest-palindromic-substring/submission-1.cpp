class Solution {
public:
     string longestPalindrome(string s) {
    string res = "";
    int resLen = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        int l = i;
        int r = j;
        while (l < r && s[l] == s[r]) {
          r--;
          l++;
        }
        if (l >= r && resLen < (j - i + 1)) {
          res = s.substr(i, j - i + 1);
          resLen = j - i + 1;
        }
      }
    }
    return res;
  }

};
