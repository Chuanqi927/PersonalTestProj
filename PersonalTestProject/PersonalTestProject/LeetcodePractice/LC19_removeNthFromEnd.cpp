#include "ListNode.h"
#include "../CPP/CPPComUtils.hpp"

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return head;
        }
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *fast = head;      // fianlly point to last node
        ListNode *slow = dummyHead; // finally point to Nth node's PREVIOUS node!!

        // 不能这样实现，会导致可能走到last node，n还没有为0
        // while (fast->next != nullptr) {
        //     if (n == 0) {
        //         slow = slow->next;
        //         fast = fast->next;
        //     } else {
        //         fast = fast->next;
        //         n--;
        //     }
        // }
        
        for (int i=0; i<n; i++) {
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};

static void LCTester19() {
    ListNode *head = new ListNode(1, new ListNode(2));
    Solution19 obj;
    ListNode *newHead = obj.removeNthFromEnd(head, 1);
    CPPComUtils::printLinkedList(newHead);
}
