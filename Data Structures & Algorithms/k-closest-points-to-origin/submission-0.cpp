class Solution {
public:
        vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxHeap;
        for (int i = 0; i < points.size(); i++)
        {
            const vector<int> point = points[i];
            const double dist = (point[0] * point[0]) + (point[1] * point[1]);
            maxHeap.push({dist, i});
        }
        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return res;
    }


};
