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
    vector<int> inorderTraversal(TreeNode *root) {
        vector <int> ret;
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            while (S.top()) {
                S.push(S.top()->left);
            }
            S.pop();
            if (!S.empty()) {
                ret.push_back(S.top()->val);
                TreeNode *top = S.top();
                S.pop();
                S.push(top->right);
            }
        }
        return ret;
    }
};