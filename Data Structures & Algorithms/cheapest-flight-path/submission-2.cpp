class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& flight : flights) {
      int s = flight[0];
      int d = flight[1];
      int p = flight[2];
      adj[s].push_back({d, p});
    }
    minHeap.push({0, src, 0});
    while (!minHeap.empty()) {
      auto [cost, node, steps] = minHeap.top();
      minHeap.pop();
      
      if (node == dst)
        return cost;
    if (steps == k+1)
        continue;
      for (const auto& neigh : adj[node]) {
        minHeap.push({cost + neigh.second, neigh.first, steps + 1});
      }
    }
    return -1;
  }



};
