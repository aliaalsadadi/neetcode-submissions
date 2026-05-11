class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int n = wordList.size();
    int m = wordList[0].size();
    vector<vector<int>> adj(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < wordList.size(); i++) {
      mp[wordList[i]] = i;
    }
    if (mp.count(endWord) == 0)
      return 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < m; k++) {
          if (wordList[i][k] != wordList[j][k]) {
            cnt++;
          }
        }
        if (cnt == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    queue<int> q;
    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int k = 0; k < m; k++) {
        if (wordList[i][k] != beginWord[k]) {
          cnt++;
        }
      }
      if (cnt == 1) {
        q.push(i);
        visited.insert(i);
      }
    }
    int res = 1;
    while (!q.empty()) {
      res++;

      int size = q.size();
      for (int i = 0; i < size; i++) {
        int node = q.front();

        q.pop();
        if (wordList[node] == endWord) {
          return res;
        }
        for (int neigh : adj[node]) {
          if (!visited.count(neigh)) {
            visited.insert(neigh);
            q.push(neigh);
          }
        }
      }
    }
    return 0;
  }


};
