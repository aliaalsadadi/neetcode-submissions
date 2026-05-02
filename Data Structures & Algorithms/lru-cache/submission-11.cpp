#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;   // LRU side
    Node* right;  // MRU side

    inline void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    inline void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        cache.reserve(capacity);
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        Node* node = it->second;
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            Node* node = it->second;
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);

        if ((int)cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

    ~LRUCache() {
        Node* cur = left;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};