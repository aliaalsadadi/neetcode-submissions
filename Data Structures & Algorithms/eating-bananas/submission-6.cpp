class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxK = *max_element(piles.begin(), piles.end());
        int l = 1;
        int r = maxK;
        int res = maxK;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            long long total = 0;
            for (const int &pile : piles)
            {
                total += (pile + mid - 1) / mid;
            }
            if (total <= h)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }


};