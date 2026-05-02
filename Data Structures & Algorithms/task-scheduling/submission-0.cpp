class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> processed;
    vector<int> freq(26);
    for (const char& t : tasks) {
      freq[t - 'A']++;
    }
    vector<pair<int, int>> arr;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0) {
        arr.emplace_back(freq[i], i);
      }
    }
    int time = 0;
    while (!arr.empty()) {
      int best_index = -1;
      for (int i = 0; i < arr.size(); i++) {
        bool ok = true;
        for (int j = max(0, time - n); j < processed.size(); j++) {
          if (j < processed.size() && processed[j] == arr[i].second) {
            ok = false;
            break;
          }
        }
        if (!ok)
          continue;
        if (best_index == -1 || arr[best_index].first < arr[i].first) {
          best_index = i;
        }
      }
      int cur = -1;
      if (best_index != -1) {
        cur = arr[best_index].second;
        arr[best_index].first--;
        if (arr[best_index].first == 0) {
          arr.erase(arr.begin() + best_index);
        }
      }
      time++;
      processed.push_back(cur);
    }
    return time;
  }

};
