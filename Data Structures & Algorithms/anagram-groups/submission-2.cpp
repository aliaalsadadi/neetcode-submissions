#include <map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //build map for each str
        vector<string> sorted_strs = {};
        unordered_map<string, vector<string>> my_map = {};
        for (const string& str: strs) {
            string sorted = str;
            std::sort(sorted.begin(),sorted.end());
            if (my_map.count(sorted)) {
                my_map[sorted].push_back(str);
            } else { 
                my_map[sorted] = {str};
            }
        }
        vector<vector<string>> result = {};
        for (auto& pair : my_map ) {
            result.push_back(pair.second);
        }
        return result;
    }
};
