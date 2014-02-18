/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) { return; }
        
        TreeLinkNode *next = root->next;
        
        while (next) {
            if (next->left != NULL) {
                next = next->left;
                break;
            }
            
            if (next->right != NULL) {
                next = next->right;
                break;
            }
            next = next->next;
        }
        
        if (root->left != NULL) {
            if (root->right != NULL) {
                root->left->next = root->right;
            } else {
                root->left->next = next;
            }
        }
        if (root->right != NULL) {
            root->right->next = next;
        }
        connect(root->right);
        connect(root->left);
        
    }
};