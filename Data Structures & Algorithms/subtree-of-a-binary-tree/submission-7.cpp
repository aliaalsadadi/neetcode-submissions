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
  bool dfsSame(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p == nullptr) {
      return false;
    } else if (q == nullptr) {
      return false;
    }
    return q->val == p->val && dfsSame(p->right, q->right) &&
           dfsSame(p->left, q->left);
  }
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (root == nullptr && subRoot == nullptr) {
      return true;
    }
    if (root == nullptr) {
        return false;
    }
    if (dfsSame(subRoot, root)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }


};
