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
  vector<int> dfsBalance(TreeNode *root) {
    if (!root) {
      return {1, 0};
    }
    vector<int> right = dfsBalance(root->right);
    vector<int> left = dfsBalance(root->left);
    if ((abs(left[1] - right[1]) > 1) || (left[0] == 0 || right[0] == 0)) {
      return {0, 1 + max(left[1], right[1])};
    } else {
      return {1, 1 + max(left[1], right[1])};
    }
  }
  bool isBalanced(TreeNode *root) { return dfsBalance(root)[0] == 1; }
};
