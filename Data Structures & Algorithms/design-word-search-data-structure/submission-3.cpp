#include <string>
#include <vector>

class TrieNode {
public:
  TrieNode *children[26];
  bool isEnd;
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    isEnd = false;
  }
};

using namespace std;

class WordDictionary {
private:
  TrieNode *root;

public:
  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *cur = root;
    for (const char &c : word) {

      int i = c - 'a';
      if (cur->children[i] == nullptr) {
        cur->children[i] = new TrieNode();
      }
      cur = cur->children[i];
    }
    cur->isEnd = true;
  }

  bool search(string word) { return dfs(word, 0, root); }

private:
  bool dfs(string word, int j, TrieNode *root) {
            TrieNode *cur = root;
    for (int i = j; i < word.size(); i++) {
      char c = word[i];
      if (c == '.') {
        for (TrieNode *cur : cur->children) {
          if (cur != nullptr && dfs(word, i + 1, cur)) {
            return true;
          }
        }
        return false;
      } else {

        if (cur->children[c - 'a'] == nullptr) {
          return false;
        }
        cur = cur->children[c - 'a'];
      }
    }
    return cur->isEnd;
  }
};
