class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<pair<int,int>> heap;
        for (int i = 0; i < points.size(); i++)
        {
            const vector<int> point = points[i];
            const double dist = (point[0] * point[0]) + (point[1] * point[1]);
            heap.push_back({dist, i});
        }
        make_heap(heap.begin(), heap.end(), greater<pair<int,int>>());

        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {

            res.push_back(points[heap.front().second]);
            pop_heap(heap.begin(),heap.end(), greater<pair<int, int>>());
            heap.pop_back();
        }
        return res;
    }



};
