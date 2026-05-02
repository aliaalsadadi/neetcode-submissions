class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    int window[26] = {0};
    int target[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
      target[s1[i] - 'a']++;
      window[s2[i] - 'a']++;
    }
    int matches = 0;
    for (int i = 0; i < 26; i++) {
      if (target[i] == window[i])
        matches++;
    }
    for (int r = s1.size(); r < s2.size(); r++) {
      if (matches == 26) {
        return true;
      }
      int index = s2[r] - 'a';
      window[index]++;

      if (target[index] == window[index]) {
        matches++;
      } else if (target[index] + 1 == window[index]) {
        matches--;
      }
      index = s2[r - s1.size()] - 'a';
      window[index]--;
      if (target[index] == window[index]) {
        matches++;
      } else if (target[index] - 1 == window[index]) {
        matches--;
      }
    }
    return matches == 26;
  }




};
