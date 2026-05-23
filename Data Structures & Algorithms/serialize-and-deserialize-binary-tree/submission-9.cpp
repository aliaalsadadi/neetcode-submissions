class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string res = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
          res += to_string(node->val);
          q.push(node->left);
          q.push(node->right);

        } else {
          res.push_back('N');
        }
        res.push_back(',');
      }
    }
    res.pop_back();
    return res;
  }


  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    cout << data;

    if (data.empty() || data[0] == 'N')
      return nullptr;
    vector<string> tokens;
    stringstream ss(data);
    string item;
    while (getline(ss, item, ',')) {
      tokens.push_back(item);
    }

    TreeNode* res = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> nodes;
    int idx = 1;
    nodes.push(res);
    while (!nodes.empty() && idx < tokens.size()) {
      int size = nodes.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = nodes.front();
        nodes.pop();
        if (idx < tokens.size() && tokens[idx] != "N") {
          node->left = new TreeNode(stoi(tokens[idx]));
          nodes.push(node->left);
        }
        idx++;
        if (idx < tokens.size() && tokens[idx] != "N") {
          node->right = new TreeNode(stoi(tokens[idx]));
          nodes.push(node->right);
        }
        idx++;
      }
    }
    return res;
  }

};
