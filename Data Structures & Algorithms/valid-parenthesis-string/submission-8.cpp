class Solution {
public:
      bool checkValidString(string s) {
    stack<int> st;
    stack<int> star;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        st.push(i);
      else if (s[i] == '*')
        star.push(i);
      else {
        if (st.empty() && star.empty()) {
          return false;
        } else if (!st.empty()) {
          st.pop();
        } else if (!star.empty()) {
          star.pop();
        }
      }
    }
    while (!st.empty() && !star.empty()) {
      int openIdx = st.top();
      st.pop();
      int closeIdx = star.top();
      star.pop();
      if (closeIdx < openIdx)
        return false;
    }
    return st.empty();
  }


};