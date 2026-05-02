class Solution {
public:
     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1);
    vector<int> sizes(n + 1);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
    }
    for (const auto& edge : edges) {
      if (!Union(edge[0], edge[1], sizes, parent)) {
        return edge;
      }
    }
    return {};
  }
  int Find(int n, vector<int>& parent) {
    while (parent[n] != n) {
      n = parent[n];
    }
    return n;
  }
  bool Union(int n1, int n2, vector<int>& sizes, vector<int>& parent) {
    int par1 = Find(n1, parent);
    int par2 = Find(n2, parent);
    if (par1 == par2) {
      return false;
    }
    if (sizes[par1] > sizes[par2]) {
      sizes[par1] += sizes[par2];
      parent[par2] = par1;
    } else {
      sizes[par2] += sizes[par1];
      parent[par1] = par2;
    }
    return true;
  }

};
