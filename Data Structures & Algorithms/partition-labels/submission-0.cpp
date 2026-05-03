class Solution {
public:
      vector<int> partitionLabels(string s) {
    int countM[26];
    for (int i = 0; i < 26; i++) {
      countM[i] = 0;
    }
    for (const char& c : s) {
      countM[c - 'a']++;
    }
    vector<int> res;
    unordered_set<char> substr;

    int i = 0;
    while (i < s.size()) {
      int l = i;
      while (!substr.empty() && i < s.size()) {
        countM[s[i] - 'a']--;
        if (!substr.count(s[i])) {
          substr.insert(s[i]);
        }

        if (countM[s[i] - 'a'] == 0) {
          substr.erase(s[i]);
        }
        i++;
      }
      substr.insert(s[i]);
      if (i - l > 0) {

        res.push_back(i - l);
      }
    }
    return res;
  }


};
