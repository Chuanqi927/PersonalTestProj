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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        while (head) {
            while (head->next && head->val == head->next->val) {
                head->next = head->next->next;
            }
            head = head->next;
        }
        return dummyHead->next;
    }
};