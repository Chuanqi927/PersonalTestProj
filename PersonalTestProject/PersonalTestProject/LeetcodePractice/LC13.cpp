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
        if (head == nullptr || n == 0) {
            return head;
        }
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;

        ListNode *slow = dummyHead;      // finally point to Nth node's PREVIOUS node!!
        ListNode *fast = head;      // fianlly point to last node

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

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        
        return dummyHead->next;
    }
    
    int main () {
        ListNode *head = new ListNode(1, new ListNode(2));
        printLinkedList(head);
        Solution *obj = new Solution();
        ListNode *newHead = obj->removeNthFromEnd(head, 1);
        printLinkedList(newHead);
        return 0;
    }

};

