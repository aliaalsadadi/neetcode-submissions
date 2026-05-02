class Solution {
public:

string encode(vector<string> &strs)
    {
        string res = "";
        for (const string &str : strs)
        {
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s)
    {
        int i = 0;
        vector<string> res;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
                j++;
            int length = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, length));
            i = j + length + 1;
        }
        return res;
    }



};
