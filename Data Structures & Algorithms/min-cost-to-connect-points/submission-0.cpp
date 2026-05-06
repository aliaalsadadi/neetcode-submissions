class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_set<int> visited(points.size());
    int cost = 0;
    pq.push({0, 0});
    while (visited.size() < points.size()) {
      auto [cst, top] = pq.top();

      pq.pop();
      if (visited.count(top))
        continue;
      cost += cst;
      visited.insert(top);
      for (int i = 0; i < points.size(); i++) {
        if (!visited.count(i)) {
          int dist = abs(points[i][0] - points[top][0]) + abs(points[i][1] - points[top][1]);
          pq.push({dist, i});
        }
      }
    }
    return cost;
  }


};
