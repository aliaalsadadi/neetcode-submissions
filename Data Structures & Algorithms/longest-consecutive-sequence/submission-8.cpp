class Solution {
public:
    int longestConsecutive(vector<int> &nums)   
    {
        unordered_map<int,int> map;
        int res = 0;
        for (const int& num: nums) {
            if (!map[num]) {
                map[num] = map[num-1] + map[num+1]+1;
                map[num-map[num-1]] = map[num];
                map[num+map[num+1]] = map[num];


                res = max(res,map[num]);
            }
        }
        return res;
    }


};
