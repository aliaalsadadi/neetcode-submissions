class Solution {
public:
    bool isValid(string s)
    {
        stack<char> my_stack;
        unordered_map<char, char> my_map = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
        for (const char &c : s)
        {
            if (my_map.contains(c))
            {
                //opening bracket
                my_stack.push(my_map[c]);
            }
            else
            {
                if (my_stack.empty() || my_stack.top() != c)
                {
                    return false;
                }
                my_stack.pop();
            }
        }
        return my_stack.empty();
    }

};
