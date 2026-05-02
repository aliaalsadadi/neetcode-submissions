class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    vector<vector<int>> res;
    bool inserted = false;
    for (int i = 0; i < intervals.size(); i++) {
      if (newInterval[0] > intervals[i][1]) {
        res.push_back(intervals[i]);
      } else if (intervals[i][0] > newInterval[1]) {
        if (!inserted) {
          res.push_back(newInterval);
          inserted = true;
        }
        res.push_back(intervals[i]);
      } else {
        int start = min(intervals[i][0], newInterval[0]);
        int end = max(intervals[i][1], newInterval[1]);
        int j = i + 1;
        while (j < intervals.size() && intervals[j][0] <= end) {
          end = max(end, intervals[j][1]);

          j++;
        }
        res.push_back({start, end});
        inserted = true;
        i = j - 1;
      }
    }
    if (!inserted) {
      res.push_back(newInterval);
    }
    return res;
  }


};
