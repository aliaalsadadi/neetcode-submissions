class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    int n = triplets.size();
    for (int i = 0; i < target.size(); i++) {
      bool found = false;
      int mx = target[i];
      int mn = target[i];
      for (int j = 0; j < n; j++) {
        if (triplets[j][0] <= target[0] && triplets[j][1] <= target[1] && triplets[j][2] <= target[2])
          if (triplets[j][i] == target[i]) {
            found = true;
          }
        mx = max(mx, triplets[j][i]);
        mn = min(mn, triplets[j][i]);
      }
      if (!found)
        return false;
    }
    return true;
  }




};
