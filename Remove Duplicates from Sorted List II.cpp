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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)   return head;
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *pre = guard;
        int val = head->val, tot = 1;
        for (ListNode *cur = head->next, *previous = head; cur; cur = cur->next, previous = previous->next) {
            if (val != cur->val) {
                if (tot == 1) {
                    pre = previous;
                }
                else {
                    pre->next = cur;
                }
                val = cur->val;
                tot = 1;
            } else {
                tot++;
            }
        }
        if (tot > 1)    pre->next = NULL;
        head = guard->next;
        delete guard;
        return head;
    }
};