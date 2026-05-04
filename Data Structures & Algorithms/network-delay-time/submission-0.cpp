class Solution {
public:
     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < times.size(); i++) {
      adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    vector<int> minTimes(n + 1, INT_MAX);
    dfs(k, adj, 0, minTimes);
    int res = *max_element(minTimes.begin() + 1, minTimes.end());
    return res == INT_MAX ? -1 : res;
  }
  void dfs(int node, unordered_map<int, vector<pair<int, int>>> adj, int currentTime, vector<int>& minTimes) {
    if (currentTime >= minTimes[node])
      return;
    minTimes[node] = min(currentTime, minTimes[node]);
    for (auto n : adj[node]) {
      dfs(n.first, adj, currentTime + n.second, minTimes);
    }
  }





};
