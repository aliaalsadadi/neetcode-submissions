class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<pair<int, int>> q;
    vector<int> res;
    int n = nums.size();
    int l = 0, r = 0;

    while (r < n) {
      while (!q.empty() && q.back().first < nums[r]) {
        q.pop_back();
      }
      q.push_back({nums[r], r});

      if (l > q.front().second) {
        q.pop_front();
      }
      if (r + 1 >= k) {
        res.push_back(q.front().first);
        l++;
      }
      r++;
    }
      return res;
  }

};
