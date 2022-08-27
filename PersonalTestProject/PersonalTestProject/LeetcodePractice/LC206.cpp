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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *lastNode = reverseList(head->next);
        // Reverse head and head->next(LinkedList)
        head->next->next = head;    
        head->next = nullptr;
        return lastNode;
    }
};



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
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev= nullptr;
        ListNode *next, *curr = head;
        while (curr) {
            next = curr->next;      // record the next node to loop
            curr->next = prev;
            // next iteration
            prev = curr;
            curr = next;
        }
        return prev;    // 此时prev是原先的最后一个node，不过他的next反向指回去了
    }
};
