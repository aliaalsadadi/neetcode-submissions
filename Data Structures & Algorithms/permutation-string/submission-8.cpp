class Solution {
public:
   bool checkInclusion(string s1, string s2) {
    sort(s1.begin(), s1.end());
    for (int i = 0; i < s2.length(); i++) {
      for (int j = i; j < s2.length(); j++) {
        string substr = s2.substr(i, j-i+1);
        sort(substr.begin(), substr.end());
        if (substr == s1)
        {
            return true;
        }
      }
    }
    return false;
  }

};
