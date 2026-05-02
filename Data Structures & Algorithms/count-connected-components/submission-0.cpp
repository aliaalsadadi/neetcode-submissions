class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n);
    vector<bool> visited(n, false);
    for (const auto& edge : edges) {
      adjList[edge[0]].push_back(edge[1]);
      adjList[edge[1]].push_back(edge[0]);
    } 
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        res++;
        dfs(visited, adjList, i);
      }
    }
    return res;
  }
  void dfs(vector<bool>& visited, const vector<vector<int>>& adjList, int node) {
    visited[node] = true;
    for (const int& nei : adjList[node]) {
      if (!visited[nei]) {
        dfs(visited, adjList, nei);
      }
    }

  }

};
