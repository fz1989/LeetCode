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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur = head, *pre = head, *last = head;
        for (int i = 0; i < n; i++) {
            last = last->next;
        }
        if (last == NULL) return head->next;
        while (last != NULL) {
            pre = cur;
            cur = cur->next;
            last = last->next;
        }
        pre->next = cur->next;
        return head;
    }
};
