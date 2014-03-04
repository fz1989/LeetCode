/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {  
    bool operator() (ListNode *a, ListNode *b) {  
        return a->val > b->val;  
    }  
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
         priority_queue<ListNode *, vector<ListNode *>, cmp> Q;
         int K = lists.size();
         for (int i = 0; i < K; i++) {
             if (lists[i] != NULL) Q.push(lists[i]);
         }
         ListNode *head = NULL ,*top = NULL, *tail = NULL;
         while (!Q.empty()) {
             top = Q.top();
             Q.pop();
             if (tail == NULL) head = top;
             else {
                 tail->next = top;
             }
             tail = top;
             if (top->next != NULL) Q.push(top->next);
         }
         return head;
    }
};