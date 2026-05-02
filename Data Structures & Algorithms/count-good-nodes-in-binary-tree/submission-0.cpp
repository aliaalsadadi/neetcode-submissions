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
      int dfsGood(TreeNode *node, int maxSofar) {
    if (!node) {
      return 0;
    }
    int count = 0;
    if (node->val >= maxSofar) {
      count = 1;
      maxSofar = node->val;
    }
    count += dfsGood(node->right, maxSofar);
    count += dfsGood(node->left, maxSofar);

    return count;
  }
  int goodNodes(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return dfsGood(root, root->val);
  }

};
