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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> st;
        vector <int> ret;
        st.push(root);
        while (!st.empty()) {
            while (st.top()) {
                st.push(st.top()->left);
            }
            st.pop();
            if (!st.empty()) {
                TreeNode *top = st.top();
                ret.push_back(top->val);
                st.pop();
                st.push(top->right);
            }
        }
        int len = ret.size();
        for (int i = 1; i < len; i++) {
            if (ret[i - 1] >= ret[i])    return false;
        }
        return true;
    }
};