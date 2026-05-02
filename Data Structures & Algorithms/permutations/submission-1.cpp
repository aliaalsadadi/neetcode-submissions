class Solution {
public:
      vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> perms = {{}};
    for (const int &num : nums) {
      vector<vector<int>> newPerms;
      for (vector<int> p : perms) {
        for (int i = 0; i < p.size() + 1; i++) {
          vector<int> p_copy = p;
          p_copy.insert(p_copy.begin() + i, num);
          newPerms.push_back(p_copy);
        }
      }
      perms = newPerms;
    }

    return perms;
  }

};
