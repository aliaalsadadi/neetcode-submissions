class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26,0);
    for (const char& t : tasks) {
      freq[t - 'A']++;
    }
    freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());

    priority_queue<int> maxHeap(freq.begin(), freq.end());
    queue<pair<int, int>> q;
    int time = 0;
    while (!maxHeap.empty() || !q.empty()) {
      time++;
      if (maxHeap.empty()) {
        time = q.front().second;
      } else {
        int top = maxHeap.top()-1;
        maxHeap.pop();
        if (top > 0) {
          q.push({top, time + n});
        }
      }
      if (!q.empty() && q.front().second == time) {
        maxHeap.push(q.front().first);
        q.pop();
      }
    }
    return time;
  }


};
