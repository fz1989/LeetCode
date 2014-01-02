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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        vector<int> cur;
        if (root == NULL)   return ret;
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
                if (front->left)    Q.push(front->left), next_cnt++;
                if (front->right)   Q.push(front->right), next_cnt++;
            }
            cnt = next_cnt;
            ret.push_back(cur);
        }
        return ret;
    }
};