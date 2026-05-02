class Solution {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        stack<float> timeStack;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++)
        {
            pairs[i] = {position[i], speed[i]};
        }
        sort(pairs.begin(), pairs.end());
        float lastTime = ((float)(target - pairs[n-1].first) / pairs[n-1].second); 
        cout << lastTime << "\n";
        int res = 1;
        for (int i = n-1; i >= 0; i--)
        {
            float time = ((float)(target - pairs[i].first) / pairs[i].second);
            if (lastTime < time)
            {
                res++;
                lastTime = time;
            }

            timeStack.push(time);
        }
        return res;
    }


};
