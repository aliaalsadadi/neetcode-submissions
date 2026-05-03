class Solution {
public:
      vector<int> partitionLabels(string s) {
    int lastIdx[26];
    for (int i = 0; i < 26; i++) {
      lastIdx[i] = -1;
    }
    for (int i = 0; i < s.size(); i++) {
      lastIdx[s[i] - 'a'] = max(i, lastIdx[s[i] - 'a']);
    }
    vector<int> res;
    int end = 0;
    int size = 0;
    for (int i = 0; i < s.size(); i++) {
      end = max(end, lastIdx[s[i] - 'a']);

      size++;
      if (i == end) {
        res.push_back(size);
        size = 0;
      }
    }
    return res;
  }




};
