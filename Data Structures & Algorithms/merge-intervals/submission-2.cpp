class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0];
             });

        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            // No next interval, so just add current
            if (i == intervals.size() - 1) {
                res.push_back(intervals[i]);
            }

            // No overlap with next interval
            else if (intervals[i + 1][0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            }

            // Overlap with next interval
            else {
                int start = intervals[i][0];
                int end = max(intervals[i][1], intervals[i + 1][1]);

                int j = i + 2;

                while (j < intervals.size() && intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                    j++;
                }

                res.push_back({start, end});
                i = j - 1;
            }
        }

        return res;
    }
};