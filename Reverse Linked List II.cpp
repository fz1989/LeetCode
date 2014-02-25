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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        if (head == NULL)   return head;
        ListNode *guard = new ListNode(0);
        ListNode *tail = guard, *cur;
        guard->next = head;
        for (int i = 1; i <= n; i++) {
            if (i == m) cur = tail;
            tail = tail->next;
        }
        for (int i = m; i < n; i++) {
            ListNode *first = cur->next;
            cur->next = cur->next->next;
            first->next = tail->next;
            tail->next = first;
        }
        head = guard->next;
        delete guard;
        return head;
    }
};