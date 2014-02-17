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
private:
    int expected;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        int arr[1024];
        expected = sum;
        helper(root, 0, arr, 0, ret);
        return ret;
    }
    void helper(TreeNode *root, int sum, int buf[], int pos, vector<vector<int> > &ret) {
        if (root == NULL) { return; }
        sum += root->val;
        buf[pos++] = root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == expected) {
                vector <int> tmp;
                for (int i = 0; i < pos; i++) {
                    tmp.push_back(buf[i]);
                }
                ret.push_back(tmp);
            }
        }
        helper(root->left, sum, buf, pos, ret);
        helper(root->right, sum, buf, pos, ret);
    }
};