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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int sPre, int ePre, int sIn, int eIn) {
        if (sPre > ePre || sIn > eIn)   return NULL;
        int key = preorder[sPre], pos = -1;

        for (int i = sIn; i <= eIn; i++) {
            if (inorder[i] == key) {
                pos = i; break;
            }
        }
        TreeNode *root = new TreeNode(key);
        root->left = buildTreeHelper(preorder, inorder, sPre + 1, sPre + pos - sIn, sIn, pos - 1);
        root->right = buildTreeHelper(preorder, inorder,sPre + pos - sIn + 1, ePre, pos + 1, eIn);
        return root;
    }

};