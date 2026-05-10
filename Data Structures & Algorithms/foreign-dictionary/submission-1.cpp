class Solution {
public:
  string foreignDictionary(vector<string>& words) {
    unordered_map<char, vector<char>> adj;
    for (const string& w : words) {
      for (const char& c : w) {
        adj[c];
      }
    }
    for (int i = 0; i < words.size() - 1; i++) {
      string word1 = words[i];
      string word2 = words[i + 1];
      int minLen = min(word1.size(), word2.size());

    if (word1.size() > word2.size() &&
        word1.substr(0, minLen) == word2.substr(0, minLen)) {
        return "";
    }
      for (int j = 0; j < min(word1.size(), word2.size()); j++) {
        if (word1[j] != word2[j]) {
          adj[word1[j]].push_back(word2[j]);
          break;
        }
      }
    }
    unordered_map<char, bool> visited;
    string res = "";
    for (const auto& [key, val] : adj) {
      if (dfs(key, adj, visited, res)) {
        return "";
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
  bool dfs(char c, unordered_map<char, vector<char>>& adj, unordered_map<char, bool>& visited, string& res) {
    if (visited.count(c)) {
      return visited[c];
    }
    visited[c] = true;
    for (const auto& neigh : adj[c]) {
      if (dfs(neigh, adj, visited, res)) {
        return true;
      }
    }
    visited[c] = false;
    res.push_back(c);
    return false;
  }



};
