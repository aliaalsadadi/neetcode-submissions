class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    vector<int> res(queries.size(), -1);
    int x = 0;
    for (const int& q : queries) {
      int minSize = -1;
      for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] <= q && q <= intervals[i][1]) {
          if (minSize == -1) {
            minSize = intervals[i][1] - intervals[i][0] + 1;
          } else {
            minSize = min(minSize, intervals[i][1] - intervals[i][0] + 1);
          }
        }
      }
      res[x] = minSize;
      x++;
    }
    return res;
  }

};
