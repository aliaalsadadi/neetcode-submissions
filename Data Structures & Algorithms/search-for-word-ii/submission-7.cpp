class Solution {
public:
    class TrieNode {
  public:
    bool is_word;
    int count;
    TrieNode* children[26];
    TrieNode() : is_word(false) {
      for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
      }
    }
    void addWord(string word) {
      TrieNode* cur = this;
      for (const char& w : word) {
        if (!cur->children[w - 'a']) {
          cur->children[w - 'a'] = new TrieNode();
        }
        cur = cur->children[w - 'a'];
      }
      cur->is_word = true;
    }
  };
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const string& word : words) {
      root->addWord(word);
    }
    vector<string> res;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        string cur;
        dfs(board, root, i, j, cur, res);
      }
    }
    return res;
  }
  void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j, string word, vector<string>& res) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || !node) {
      return;
    }

    char temp = board[i][j];
    int pos = board[i][j] - 'a';

    word += board[i][j];
    node = node->children[pos];
    if (node && node->is_word) {
      res.push_back(word);
      node->is_word = false;
    } else if (!node) {
        return;
    }
    board[i][j] = '*';
    dfs(board, node, i + 1, j, word, res);
    dfs(board, node, i - 1, j, word, res);
    dfs(board, node, i, j + 1, word, res);
    dfs(board, node, i, j - 1, word, res);
    board[i][j] = temp;
  }





};
