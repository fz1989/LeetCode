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
    bool isSymmetric(TreeNode *root) {
        if (!root)   return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode *left, TreeNode *right) {
        if (left && right) {
            if (left->val == right->val) {
                return helper(left->left, right->right) && helper(left->right, right->left);
            } else {
                return false;
            }
        } else if (!left && !right) {
            return true;
        } else {
            return false;
        }
    }
};