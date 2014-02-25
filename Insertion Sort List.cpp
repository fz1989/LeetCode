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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)   return NULL;
        ListNode *guard = new ListNode(0);
        guard->next = head;
        for (ListNode *cur = head->next, *previous = head; cur;) {
            ListNode *tmp = cur;
            cur = cur->next;
            ListNode *pre;
            for (pre= guard; pre->next != cur; pre = pre->next) {
                if (tmp->val < pre->next->val) {
                    break;
                }
            }
            if (pre->next == cur) {
                previous = previous->next;
            } else {
                 previous->next = tmp->next;
                 tmp->next = pre->next;
                 pre->next = tmp;
            }
        }
        head = guard->next;
        delete guard;
        return head;
    }
};