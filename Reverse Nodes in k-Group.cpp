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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1) return head;
        int len = 0;
        for (ListNode * cur = head; cur; cur=cur->next) {
            len++;
        }
        int cnt = len / k;
        for (int i = 0; i < cnt; i++) {
            head = reverseList(head, i * k + 1, i * k + k);
        }
        return head;
    }
    ListNode *reverseList(ListNode *head, int m, int n) {
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