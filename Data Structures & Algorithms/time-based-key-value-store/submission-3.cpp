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
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (keyStore[key][mid].second == timestamp)
            {
                return keyStore[key][mid].first;
            }
            else if (keyStore[key][mid].second > timestamp)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (r < 0) return "";  // queried timestamp is before all stored timestamps
        return keyStore[key][r].first;
    }
};
