class Solution {
public:
      vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> adj;
    sort(tickets.begin(), tickets.end());
    for (int i = 0; i < tickets.size(); i++) {
      adj[tickets[i][0]].push_back(tickets[i][1]);
    }
    vector<string> res = {"JFK"};
    int n = tickets.size();
    dfs(adj, "JFK", res, n);
    return res;
  }
  bool dfs(unordered_map<string, vector<string>>& adj, string cur, vector<string>& res, int n) {
    if (res.size() == n + 1) {
      return true;
    }
    if (!adj.count(cur))
      return false;
    vector<string> temp = adj[cur];
    for (int i = 0; i < temp.size(); i++) {
      res.push_back(temp[i]);
      adj[cur].erase(adj[cur].begin() + i);
      if (dfs(adj, temp[i], res, n)) {
        return true;
      }
      adj[cur].insert(adj[cur].begin() + i, temp[i]);
      res.pop_back();
    }
    return false;
  }

};
