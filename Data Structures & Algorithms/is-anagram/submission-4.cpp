#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_map = {};
        map<char, int> t_map = {};
        for (int i=0;i<s.length();i++) {
            if (s_map.count(s[i])) { 
                s_map[s[i]] += 1;
            } else {
                s_map[s[i]] = 1;
            }
        }
        for (int i=0;i<t.length();i++) {
            if (t_map.count(t[i])) { 
                t_map[t[i]] += 1;
            } else {
                t_map[t[i]] = 1;
            }
        }
        return t_map == s_map;
    }
};
