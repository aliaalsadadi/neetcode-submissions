class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> keyStore;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        keyStore[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp)
    {
        if (!keyStore.count(key) || !keyStore.contains(key))
        {
            return "";
        }
        int n = keyStore[key].size();
        int l = 0;
        int r = n - 1;
        string res = "";
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (keyStore[key][mid].second <= timestamp)
            {
                res = keyStore[key][mid].first;
                l = mid+1;
            }
            else if (keyStore[key][mid].second > timestamp)
            {
                r = mid - 1;
            }

        }
        return res;
    }
};
