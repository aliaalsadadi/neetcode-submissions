class Solution {
public:
     vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(0, 0, n, res, "");
    return res;
  }
    void backtrack(int open, int close, int n, vector<string> &res, string cur) {
    if (open == close && open == n) {
      res.push_back(cur);
      return;
    }

    if (open < n) {
      cur += "(";
      backtrack(open + 1, close, n, res, cur);
      cur.pop_back();
    }
    if (close < open) {
      cur += ")";
      backtrack(open, close + 1, n, res, cur);
      cur.pop_back();
    }
  }


};
