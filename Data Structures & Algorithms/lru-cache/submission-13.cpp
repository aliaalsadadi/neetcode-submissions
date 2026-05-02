#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> dll; // {key, value}, front = LRU, back = MRU
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) : cap(capacity) {
        mp.reserve(capacity * 2);
        mp.max_load_factor(0.7f);
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        dll.splice(dll.end(), dll, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);

        if (it != mp.end()) {
            it->second->second = value;
            dll.splice(dll.end(), dll, it->second);
            return;
        }

        if ((int)dll.size() == cap) {
            mp.erase(dll.front().first);
            dll.pop_front();
        }

        dll.emplace_back(key, value);
        auto nodeIt = prev(dll.end());
        mp[key] = nodeIt;
    }
};