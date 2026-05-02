class Solution {
public:
     bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
    for (int i = 0; i < edges.size(); i++) {
      adjList[edges[i][0]].push_back(edges[i][1]);
      adjList[edges[i][1]].push_back(edges[i][0]);
    }
    if (!helperDfs(0, -1, adjList, visited)) {
        return false;
      }
    return visited.size() == n;
  }
  bool helperDfs(int i, int prev, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited) {
    if (visited.count(i)) {
      return false;
    }
    visited.insert(i);
    for (const int& node : adjList[i]) {
      if (node == prev) {
        continue;
      }
      if (!helperDfs(node, i, adjList, visited)) {
        return false;
      }
    }
    return true;
  }

};
