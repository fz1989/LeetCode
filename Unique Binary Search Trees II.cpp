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
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
    vector<TreeNode *> generateTreesHelper(int start, int end) {
        vector<TreeNode *> ret;
        if (start > end) {
            ret.push_back(NULL);
        } else if (start == end) {
            ret.push_back(new TreeNode(start));
        } else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode *> left = generateTreesHelper(start, i - 1);
                vector<TreeNode *> right = generateTreesHelper(i + 1, end);
                int s_left = left.size(), s_right = right.size();
                for (int j = 0; j < s_left; j++) {
                    for (int k = 0; k < s_right; k++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        ret.push_back(root);
                    }
                }

            }
        }
        return ret;
    }
};