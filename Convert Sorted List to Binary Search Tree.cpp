/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)   return NULL;
        ListNode *cur = head;
        int length = 0;
        while (cur) {
            length++;
            cur = cur->next;
        }
        return sortedListToBSTHelper(head, length);
    }
    TreeNode *sortedListToBSTHelper(ListNode *head, int length) {
        if (head == NULL || length <= 0)    return NULL;
        ListNode *cur = head;
        for (int i = 0; i < length / 2; i++) {
            cur = cur->next;
        }
        TreeNode *root = new TreeNode(cur->val);
        root->left = sortedListToBSTHelper(head, length / 2);
        root->right = sortedListToBSTHelper(cur->next, length - (length) / 2 - 1);
    }
};