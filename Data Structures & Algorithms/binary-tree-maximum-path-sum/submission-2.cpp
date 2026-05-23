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
  int dfs(TreeNode* root, int& res) {
    if (root == nullptr)
      return 0;
    int leftMax = dfs(root->left, res);
    int rightMax = dfs(root->right, res);
    leftMax = max(0, leftMax);
    rightMax = max(0, rightMax);
    res = max(res, root->val + leftMax + rightMax);
    return root->val + max(leftMax , rightMax);
  }


};
