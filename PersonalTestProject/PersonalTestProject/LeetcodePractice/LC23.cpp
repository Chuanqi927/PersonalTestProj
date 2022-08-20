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

#include <vector>
#include <queue>

class Solution {
public:
    struct comparator {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };


    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode *dummyHead = new ListNode();
        ListNode *index = dummyHead;

        std::priority_queue<ListNode*, std::vector<ListNode*>, comparator> smallestPriorityQueue;

        // add headNode of every list into queue
        for (ListNode *head : lists) {
            if (head != nullptr) {
                smallestPriorityQueue.push(head);
            }
        }
        while (!smallestPriorityQueue.empty()) {
            // get smallest headNode
            ListNode *smallestNode = smallestPriorityQueue.top();
            smallestPriorityQueue.pop();
            index->next = smallestNode;
            index = index->next;

            // add the rest of headNode into queue
            if (smallestNode->next != nullptr) {
                smallestPriorityQueue.push(smallestNode->next);
            }
        }
        return dummyHead->next;
    }
};