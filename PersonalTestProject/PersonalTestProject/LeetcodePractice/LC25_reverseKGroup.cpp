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
    // 翻转一个子链表，并且返回新的头与尾
    std::pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* ptr = head;
        while (prev != tail) {
            ListNode* nex = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* prev = dummyHead;

        while (head) {
            ListNode* tail = prev;
            
            // find tail
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {    // check length >= k
                    return dummyHead->next;
                }
            }
            ListNode* next = tail->next;

            //reverse
            std::pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;

            //link
            prev->next = head;
            tail->next = next;

            //prepare for next iteration
            prev = tail;
            head = tail->next;
        }

        return dummyHead->next;
    }
};
