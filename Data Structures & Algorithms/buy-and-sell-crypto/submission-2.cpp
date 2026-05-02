class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (const int &p : prices)
        {
            if (p < minPrice)
            {
                minPrice = p;
            }
            else
            {
                maxProfit = max(maxProfit, (p - minPrice));
            }
        }
        return maxProfit;
    }

};
