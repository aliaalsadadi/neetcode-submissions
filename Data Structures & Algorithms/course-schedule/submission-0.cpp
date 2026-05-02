class Solution {
public:
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> preMap(numCourses);
    unordered_set<int> visitSet;
    for (int i = 0; i < prerequisites.size(); i++) {
      preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for (int i = 0; i < prerequisites.size(); i++) {
      if (!dfs(prerequisites[i][0], preMap, visitSet))
        return false;
    }
    return true;
  }
  bool dfs(int crs, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visitSet) {
    if (visitSet.count(crs))
      return false;
    if (preMap[crs].empty())
      return true;
    visitSet.insert(crs);
    for (const int& pre : preMap[crs]) {
      if (!dfs(pre, preMap, visitSet)) {
        return false;
      }
    }
    visitSet.erase(crs);
    return true;
  }

};
