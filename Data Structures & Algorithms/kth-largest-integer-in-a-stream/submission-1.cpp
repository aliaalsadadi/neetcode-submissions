class KthLargest
{
public:
    vector<int> arr;
    int topk;
    KthLargest(int k, vector<int> &nums)
    {
        this->arr = nums;
        this->topk = k;
    }

    int add(int val)
    {
        arr.push_back(val);
        sort(this->arr.begin(), this->arr.end());
        return arr[arr.size()-topk];
    }
};
