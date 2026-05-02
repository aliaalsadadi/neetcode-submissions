
class TrieNode {
public:
  TrieNode *children[26];
  bool isEnd;
  TrieNode()  {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
      isEnd = false;
    }
  };
};

class PrefixTree {
private:
  TrieNode *root;

public:
  PrefixTree() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *cur = root;
    for (const char &c : word) {
      int index = c - 'a';
      if (cur->children[index] == nullptr) {
        cur->children[index] = new TrieNode();
      }
      cur = cur->children[index];
    }
    cur->isEnd = true;
  }

  bool search(string word) {
    TrieNode *cur = root;
    for (const char &c : word) {
      int i = c - 'a';
      if (cur->children[i] == nullptr) {
        return false;
      }
      cur = cur->children[i];
    }
    return cur->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for (const char &c : prefix) {
      int i = c - 'a';
      if (cur->children[i] == nullptr) {
        return false;
      }
      cur = cur->children[i];
    }
    return true;
  }
};
