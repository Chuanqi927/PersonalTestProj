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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *dummyhead = new ListNode();
        ListNode *ptr = dummyhead;
        bool addForward;

        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            } 
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (addForward) {
                sum++;
            }

            if (sum >= 10) {
                addForward = true;
                sum = sum % 10;
            } else {
                addForward = false;
            }
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }
        if (addForward) {
            ptr->next = new ListNode(1);
        }
        return dummyhead->next;
    }
};