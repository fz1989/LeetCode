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
    bool isBalanced(TreeNode *root) {
        if (root == NULL)   return true;
        if (abs(height(root->left) - height(root->right)) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
    int height(TreeNode *root) {
        if (root == 0)  return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};