#include <set>
#include <vector>
class Solution {
public:
     bool hasDuplicate(vector<int> &nums)
    {
        unordered_set<int> my_set;
        for (const int& num : nums)
        {
            if (my_set.contains(num))
            {
                return true;
            }
            my_set.insert(num);
        }
        return false;
    }

};