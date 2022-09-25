#include "ListNode.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return head;
        }
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *fast = head;
        ListNode *slow = dummyHead;
        
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