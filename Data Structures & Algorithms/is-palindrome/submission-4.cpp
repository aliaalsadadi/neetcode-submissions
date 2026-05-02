class Solution {
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
            return true;
        string copys;
        int i = 0;
        for (const char &c : s)
        {
            if (isalnum(c))
            {
                copys += tolower(c);
                i++;
            }
        }
        string reverses(copys.rbegin(), copys.rend());
        return copys == reverses;
    }


};
