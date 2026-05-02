class Solution {
public:
        int lastStoneWeight(vector<int> &stones)
    {
        while (stones.size() >= 2)
        {
            sort(stones.begin(), stones.end());
            int x = stones[stones.size() - 2], y = stones[stones.size() - 1];
            if (x == y)
            {
                stones.pop_back();
                stones.pop_back();
            }
            else if (x < y)
            {
                stones[stones.size() - 1] -= x;
                stones.erase(stones.end() - 2);
            }
        }
        if (stones.size() == 0) {return 0;}
        return stones[0];
    }

};
