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
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;

    bool left = isValidLeft(root->left, root->val);
    bool right = isValidRight(root->right, root->val);

    return left && right && isValidBST(root->left) && isValidBST(root->right);
  }

  bool isValidRight(TreeNode *root, int val) {
    if (!root)
      return true;
    if (root->val <= val) {
      return false;
    }
    return true && isValidRight(root->right, val) &&
           isValidRight(root->left, val);
  }

  bool isValidLeft(TreeNode *root, int val) {
    if (!root)
      return true;
    if (root->val >= val) {
      return false;
    }
    return true && isValidLeft(root->right, val) &&
           isValidLeft(root->left, val);
  }
};
