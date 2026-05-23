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
      int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    dfs(root, res);
    return res;
  }
    void dfs(TreeNode* root, int& res) {
    if (root == nullptr)
      return;
    int leftMax = getMax(root->left);
    int rightMax = getMax(root->right);
    res = max(res, root->val + leftMax + rightMax);
    dfs(root->right, res);
    dfs(root->left, res);
  }

  int getMax(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int leftMax = getMax(root->left);
    int rightMax = getMax(root->right);
    int path = root->val + max(leftMax, rightMax);
    return max(0, path);
  }

};
