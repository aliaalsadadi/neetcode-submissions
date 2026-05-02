class Solution {
public:
        bool checkInclusion(string s1, string s2) {
            if (s1.size() > s2.size()) 
            {
                return false;
            }
    int s1Count[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
      s1Count[s1[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      cout << i << " " << s1Count[i];
    }
    cout << "\n";
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
      int count[26] = {0};
      for (int j = 0; j < s1.size(); j++) {
        count[s2[i + j] - 'a']++;
      }
      if (equal(s1Count, s1Count + 26, count)) {
        return true;
      }
    }
    return false;
  }




};
