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
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSumHelper(root, 0, sum);
    }
    bool hasPathSumHelper(TreeNode *root, int sum, int target) {
        if (root == NULL)   return false;
        if (root->left == NULL && root->right == NULL) 
            return sum + root->val == target;
        bool ret = false;
        if (root->left)
            ret |= hasPathSumHelper(root->left, sum + root->val, target);
        if (root->right)
            ret |= hasPathSumHelper(root->right, sum + root->val, target);    
        return ret;
    }
};