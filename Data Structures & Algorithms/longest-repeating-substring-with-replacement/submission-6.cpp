class Solution {
public:
  int characterReplacement(string s, int k) {
    int res = 0; // 1
    int maxf = 0; // 1
    unordered_map<char, int> count(26); // {A:1 B:}
    int l = 0;
    for (int r = 0; r < s.size(); r++) { //r =1
    count[s[r]]++;
      maxf = max(maxf, count[s[r]]); // 1
      while (r - l + 1 - maxf > k) { 
        count[s[l]]--;
        l++;
      } 
    res = max(res, r - l + 1);

    }
    return res;
  }


};
