class Solution {
public:
        bool isPalindrome(string s)
    {
        if (s.empty())
            return true;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (l < s.size()-1 && !isalnum(s[l]))
                l++;
            while (r >= 0 && !isalnum(s[r]))
                r--;
            if (l>r) return true;
            if (tolower(s[r]) != tolower(s[l]))
                return false;
            l++;
            r--;
        }
        return true;
    }

};
