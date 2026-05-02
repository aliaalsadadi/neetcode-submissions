class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mps;
        for (int i=0;i<s.size();i++)
        {
            mps[s[i]]++;
        }
        map<char,int> mpt;
        for (int i=0;i<t.size();i++)
        {
            mpt[t[i]]++;
        }
        return mpt == mps;

    }
};
