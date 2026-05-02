class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    int goal = n - 1;
    for  (int i =n-2;i>=0;i--) {
      int dist = goal - i;
      if (dist <= nums[i]) {
        goal = i;
      }
    }
    return goal == 0;
  }


};
