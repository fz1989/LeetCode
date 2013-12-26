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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int N = num.size();
        if (N == 0) return NULL;
        return helper(0, N - 1, num);
    }
    TreeNode *helper(int left, int right, vector<int> &num) {
        int mid = (left + right) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        if (left == right) return root;
        if (left + 1 <= mid)  root->left = helper(left, mid - 1, num);
        if (mid + 1 <= right) root->right = helper(mid + 1, right, num);
        return root;
    }
};