class Solution {
public:
  vector<vector<int>> res;

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    generateSubsets(0, candidates, target, 0, cur);
    return res;
  }

private:
  void generateSubsets(int i, const vector<int> &candidates, int target,
                       int sum, vector<int> &cur) {

    if (target == sum) {
      res.push_back(cur);
      return;
    }
    if (i >= candidates.size() || sum > target) {
      return;
    }
    cur.push_back(candidates[i]);
    generateSubsets(i + 1, candidates, target, sum + candidates[i], cur);
    while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
      i++;
    }
    cur.pop_back();
    generateSubsets(i + 1, candidates, target, sum, cur);
  }
};