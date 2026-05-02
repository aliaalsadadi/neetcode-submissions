#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map = {};
        unordered_map<char, int> t_map = {};
        for (auto c: s) {
            s_map[c]++;
        }
        for (auto c: t) {
            t_map[c]++;
        }
        return t_map == s_map;
    }
};
