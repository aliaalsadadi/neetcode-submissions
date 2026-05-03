class Solution {
public:
    bool checkValidString(string s) {
    int leftMin = 0;
    int leftMax = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        leftMin++;
        leftMax++;
      } else if (s[i] == ')') {
        leftMin--;
        if (leftMin < 0)
          leftMin = 0;
        leftMax--;
        if (leftMax < 0) {
          return false;
        }
      } else {
        leftMin--;
        leftMax++;
        leftMin = max(leftMin, 0);
      }
    }
    return leftMin == 0;
  }

};