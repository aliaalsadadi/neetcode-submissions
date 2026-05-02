/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
      void traverseToVec(TreeNode *node, vector<int> &res) {
    if (!node) {
      return;
    }
    traverseToVec(node->left, res);
    res.push_back(node->val);
    traverseToVec(node->right, res);
  };
  int kthSmallest(TreeNode *root, int k) {
    if (!root)
      return 0;
    vector<int> res;
    traverseToVec(root, res);
    return res[k-1];
  }

};
