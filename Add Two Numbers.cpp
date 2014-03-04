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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *tail = NULL;
        if (l1 == NULL && l2 == NULL)   return NULL;
        else if (l1 == NULL)            return l2;
        else if (l2 == NULL)            return l1;
        int adder = 0;
        while (l1 && l2) {
            int val = l1->val + l2->val + adder;
            ListNode *cur = new ListNode(val % 10);
            adder = val / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (tail == NULL) {
                head = cur;
            } else {
                tail->next = cur;
            }
            tail = cur;
        }
        while (l1) {
            int val = l1->val + adder;
            l1->val = val % 10;
            adder = val / 10;
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val + adder;
            l2->val = val % 10;
            adder = val / 10;
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
            
        }
        if (adder) {
            tail->next = new ListNode(1);
        }
        return head;
    }
};