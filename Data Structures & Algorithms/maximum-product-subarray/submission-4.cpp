class Solution {
public:
     int maxProduct(vector<int> &nums) {
    int res = nums[0];
    int curMin = 1;
    int curMax = 1;

    for (int num : nums) {
      int tmp = num * curMax;
      curMax = max(max(num * curMax, num * curMin), num);
      curMin = min(min(tmp, curMin * num), num);
      res = max(curMax, res);
    }
    return res;
  }

};