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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*>S;
        S.push(root);
        while (!S.empty() && S.top()) {
            ret.push_back(S.top()->val);
            TreeNode * top = S.top();
            S.pop();
            if (top->right) S.push(top->right);
            if (top->left)  S.push(top->left);
            
        }
        return ret;
    }
};