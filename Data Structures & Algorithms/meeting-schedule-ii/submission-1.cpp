/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
    int res = 0;
    vector<int> start(intervals.size());
    vector<int> end(intervals.size());


    for (const auto& i : intervals) {
      start.push_back(i.start);
      end.push_back(i.end);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < start.size()) {
      if (start[i] < end[j]) {
        i++;
        count++;
      } else {
        j++;
        count--;
      }

      res = max(res, count);
    }
    return res;
  }


};
