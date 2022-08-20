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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *prev = dummyHead;
        while (head && head->next) {
            ListNode *first = head;
            ListNode *second = head->next;
            // swap 
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // loop for next iteration
            prev = first;
            head = first->next;
        }
        return dummyHead->next;
    }
};