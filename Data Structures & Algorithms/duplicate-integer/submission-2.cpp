#include <set>
#include <vector>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> nums_set = {};
        for (int num : nums) {
            if (nums_set.count(num)) {
                return true;
            }
            nums_set.insert(num);
        }
        return false;
    }
};