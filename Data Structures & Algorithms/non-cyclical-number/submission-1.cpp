class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (!visited.count(n)) {
            visited.insert(n);
            int temp = helper(n);
            if (temp == 1) {
                return true;
            }
            n = temp;
        }
        return false;
    }
    int helper(int n) {
        int res = 0;
        int temp = n;
        while (temp != 0) {
            res += (temp % 10 ) * (temp % 10);
            temp /= 10;
        }
        return res;
    }
};
