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
    void recoverTree(TreeNode *root) {
        stack<TreeNode *>st;
        st.push(root);
        TreeNode *pre = NULL, *cur = NULL, *first = NULL, *second= NULL;
        while (!st.empty()) {
            while (st.top()) {
                st.push(st.top()->left);
            }
            st.pop();
            if (!st.empty()) {
                cur = st.top();
                if (pre != NULL && pre->val > cur->val) {
                    if (first == NULL) {
                        first = pre;
                    }
                    second = cur;
                }
                pre = cur;
                st.pop();
                st.push(cur->right);
            }
        }
        swap(first->val, second->val);
    }
};