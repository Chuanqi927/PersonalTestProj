#include "ListNode.h"
#include <set>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> set;
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        // add all node of A into set
        while (ptrA != nullptr) {
            set.insert(ptrA);
            ptrA = ptrA->next;
        }
        while (ptrB != nullptr) {
            if (set.find(ptrB) != set.end()) {
                return ptrB;
            }
            ptrB = ptrB->next;
        }
        return nullptr;
    }
};