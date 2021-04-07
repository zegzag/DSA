#include "include/structure.h"
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* H = new ListNode(0);
        H->next = head;
        auto p1 = H, p2 = H;
        for (int i = 1; i < n; i++) {
            p2 = p2->next;
        }
        while(p2->next->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // auto p_del = p1->next;
        p1->next = p1->next->next;
        // delete  p_del;
        return H->next;
    }
};