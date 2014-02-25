/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)   return head;
        ListNode *cur = head, *pBigTail = NULL, *pBigHead = NULL;
        ListNode *pSmallTail = NULL, *pSmallHead = NULL;
        while (cur != NULL) {
            if (cur->val >= x) {
                if (pBigHead == NULL) {
                    pBigHead = pBigTail = cur;
                } else {
                    pBigTail->next = cur;
                    pBigTail = cur;
                }
            } else {
                if (pSmallHead == NULL) {
                    pSmallHead = pSmallTail = cur;
                } else {
                    pSmallTail->next = cur;
                    pSmallTail = cur;
                }
            }
            cur = cur->next;
        }
        if (pBigTail)   pBigTail->next = NULL;
        if (pSmallHead == NULL) return pBigHead;
        else {
            pSmallTail->next = pBigHead;
            return pSmallHead;
        }
    }
};