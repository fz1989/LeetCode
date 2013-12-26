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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)   return head;
        ListNode *cur, *next, *ret, *pre;
        cur = head;
        next = cur->next;
        head->next = next->next;
        next->next = head;
        ret = next;
        while (cur && cur->next && cur->next->next) {
            pre = cur->next;
            next = cur->next->next;
            cur->next = next;
            pre->next = next->next;
            next->next = pre;
            cur = pre;
        }
        return ret;
    }
};