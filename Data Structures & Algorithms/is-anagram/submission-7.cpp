#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){return false;}
        array<int, 26> freq_s = {};
        array<int, 26> freq_t = {};
        for (int i=0;i<s.length();i++){
            freq_s[s[i]-'a']++;
            freq_t[t[i]-'a']++;
        }
        return freq_t == freq_s;
    }
};
