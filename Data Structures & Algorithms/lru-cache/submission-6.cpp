#include <unordered_map>

using namespace std;
class Node {
public:
  int key;
  int val;
  Node *prev;
  Node *next;
  Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
  unordered_map<int, Node *> cache;
  int cap;
  Node *left;
  Node *right;

public:
  LRUCache(int capacity) : cap(capacity) {
    cache.clear();
    left = new Node(0, 0);
    right = new Node(0, 0);
    left->next = right;
    right->prev = left;
  }
  void remove(Node *node) {
    Node *l = node->prev;
    Node *r = node->next;
    l->next = r;
    r->prev = l;
  };
  void insert(Node *node) {
    Node *l = right->prev;
    l->next = node;
    node->next = right;
    right->prev = node;
    node->prev = l;
  };
  int get(int key) {
    if (cache.count(key)) {
      remove(cache[key]);
      insert(cache[key]);
      return cache[key]->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (cache.count(key)) {
      remove(cache[key]);
    }
    Node *newNode = new Node(key, value);
    cache[key] = newNode;
    insert(newNode);
    if (cache.size() > cap) {
      Node *lru = left->next;
      remove(lru);
      cache.erase(lru->key);
      delete lru;
    }
  }
};
