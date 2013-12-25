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
        if (head == NULL) return head;
        int pre = head->val;
        ListNode *ret = head;
        while (head != NULL && head->next != NULL) {
            ListNode *now = head->next;
            if (now->val == pre) {
                head->next = now->next;
                free(now);
            } else {
                head = now;
                pre = now->val;
            }
        }
        return ret;
    }
};