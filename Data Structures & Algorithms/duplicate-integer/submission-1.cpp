#include <set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> s;
        for (int x: nums)
        {
            std::cout << x << '\n';
            std::cout << s.count(x) << '\n';

            if (s.count(x) == 1) return true;
            s.insert(x);
        }
        return false;
    }
};
