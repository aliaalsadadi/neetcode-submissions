class Solution {
public:
  unordered_map<char, vector<char>> DIGITS_MAP = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

      vector<string> letterCombinations(string digits) {
    vector<string> res;
    for (const char &c : digits) {
      vector<string> newRes;
      if (res.empty()) {
        for (const char &mapC : DIGITS_MAP[c]) {
          newRes.push_back({mapC});
        }
      } else {
        for (int i = 0; i < res.size(); i++) {
          for (const char &mapC : DIGITS_MAP[c]) {
            newRes.push_back(res[i] + mapC);
          }
        }
      }
      res = newRes;
    }
    return res;
  }

};
