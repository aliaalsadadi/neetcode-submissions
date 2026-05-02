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
        sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a,const pair<int,int>& b) { 
            return a.first > b.first;
            });
        float lastTime = ((float)(target - pairs[0].first) / pairs[0].second); 
        cout << lastTime << "\n";
        int res = 1;
        for (int i = 0; i < n; i++)
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
