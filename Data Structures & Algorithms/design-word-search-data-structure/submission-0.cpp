#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (const char& c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        vector<TrieNode*> cur = {root};

        for (const char& c : word) {
            vector<TrieNode*> next;

            if (c == '.') {
                for (TrieNode* cr : cur) {
                    for (int i = 0; i < 26; i++) {
                        if (cr->children[i] != nullptr) {
                            next.push_back(cr->children[i]);
                        }
                    }
                }
            } else {
                int i = c - 'a';
                for (TrieNode* cr : cur) {
                    if (cr->children[i] != nullptr) {
                        next.push_back(cr->children[i]);
                    }
                }
            }

            cur = next;

            if (cur.empty()) {
                return false;
            }
        }

        for (TrieNode* cr : cur) {
            if (cr->isEnd) {
                return true;
            }
        }
        return false;
    }
};