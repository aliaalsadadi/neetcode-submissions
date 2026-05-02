#include <array>
#include <string>
#include <vector>
#include <unordered_map>
class Solution {
public:
    string buildArr(const string &str)
    {
        int count[26] = {};
        for (auto &c : str)
        {
            count[c - 'a']++;
        }
        string res;
        for (int i=0;i<26;i++) {
            res += to_string(count[i]) + "#";
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        //build map for each str
        unordered_map<string, vector<string>> my_map = {};
        for (const string &str : strs)
        { 
            string arr = buildArr(str);
            if (my_map.count(arr))
            {
                my_map[arr].push_back(str);
            }
            else
            {
                my_map[arr] = {str};
            }
        }
        vector<vector<string>> result = {};
        for (auto &pair : my_map)
        {
            result.push_back(pair.second);
        }
        return result;
    }

};
