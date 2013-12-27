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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        vector <int> cur;
        if (root == NULL) return ret;
        queue<TreeNode *> Q;
        Q.push(root);
        int cnt = 1;
        while (!Q.empty()) {
            int next_cnt = 0;
            cur.clear();
            for (int i = 0; i < cnt; i++) {
                TreeNode *front = Q.front();
                cur.push_back(front->val);
                Q.pop();
                
                if (front->left)  next_cnt++, Q.push(front->left);
                if (front->right) next_cnt++, Q.push(front->right);
            }
            cnt = next_cnt;
            ret.push_back(cur);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};