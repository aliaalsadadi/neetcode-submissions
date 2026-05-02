class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = *max_element(piles.begin(), piles.end());

        for (int i = 1; i <= maxK; i++) {
            long long total = 0;
            for (const int& pile : piles) {
                total += (pile + i - 1LL) / i;
            }
            if (total <= h) {
                return i;
            }
        }
        return maxK;
    }
};