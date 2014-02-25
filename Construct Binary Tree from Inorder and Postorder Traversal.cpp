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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int sIn, int eIn, int sPost, int ePost) {
        if (sIn > eIn || sPost > ePost) return NULL;
        int key = postorder[ePost], pos;
        for (int i = eIn; i >= sIn; i--) {
            if (inorder[i] == key) {
                pos = i; break;
            }
        }
        TreeNode *root = new TreeNode(key);
        root->left = buildTreeHelper(inorder, postorder, sIn, pos - 1, sPost, sPost + pos - sIn - 1);
        root->right = buildTreeHelper(inorder, postorder, pos + 1, eIn, sPost + pos - sIn, ePost - 1);
        return root;
    }
};