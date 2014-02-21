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
    void flatten(TreeNode *root) {
        if (root == NULL)   return;
        stack <TreeNode *> st;
        st.push(root);
        TreeNode * pre = NULL;
        while (!st.empty()) {
            TreeNode *now = st.top(); st.pop();
            if (pre == NULL)    pre = now;
            else {
                pre->left = NULL;
                pre->right = now;
                pre = now;
            }
            if (now->right) st.push(now->right);
            if (now->left)  st.push(now->left);
        }
        
        
    }
};