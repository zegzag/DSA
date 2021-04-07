#include "include/structure.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        auto h1 = head1;
        auto h2 = head2;
        auto p = head;
        while(p != nullptr) {
            if (p->val < x) {
                h1->next = p;
                h1 = h1->next;
            } else {
                h2->next = p;
                h2 = h2->next;
            }
            p = p->next;
        }
        h2->next =nullptr;
        h1->next = head2->next;
        head = head1->next;
        delete head1;
        delete head2;
        return head;
    }
};