/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int ret = 0;
        if (root == NULL)   return 0;
        helper(root, 0, ret);
        return ret;
    }
    void helper(TreeNode *root, int cur, int &ret) {
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            ret += cur;
            return;
        }
        if (root->right)    helper(root->right, cur, ret);
        if (root->left)     helper(root->left, cur, ret);
    }
};