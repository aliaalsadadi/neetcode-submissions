class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (const int &num : nums) {
      sum += num;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int target = sum / 2;
    unordered_set<int> dp;
          dp.insert(0);
    for (const int &num : nums) {
      unordered_set<int> maDp = dp;
      for (const int &i : dp) {
        if (num + i == target) {
          return true;
        }
        maDp.insert(i + num);
      }
      dp = maDp;
    }
    return false;
  }


};
