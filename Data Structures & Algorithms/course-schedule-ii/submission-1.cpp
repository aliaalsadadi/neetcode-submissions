class Solution {
public:
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> output;
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visitSet;
    vector<int> state(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
      preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for (int i = 0; i < numCourses; i++) {
      if (!dfs(state, output, i, preMap, visitSet)) {
        return {};
      }
    }
    return output;
  }
  bool dfs(vector<int>& state, vector<int>& output, int crs, unordered_map<int, vector<int>>& preMap,
           unordered_set<int>& visitSet) {
    if (visitSet.count(crs))
      return false;
    if (state[crs] == 1) {
      return true;
    }
    if (preMap[crs].empty()){
      state[crs] = 1;
       output.push_back(crs);  
       return true;
    }
    
    visitSet.insert(crs);
    state[crs] = 1;
    for (const int& pre : preMap[crs]) {
      if (!dfs(state, output, pre, preMap, visitSet)) {
        return false;
      }
    }
    output.push_back(crs);
    visitSet.erase(crs);
    return true;
  }


};
