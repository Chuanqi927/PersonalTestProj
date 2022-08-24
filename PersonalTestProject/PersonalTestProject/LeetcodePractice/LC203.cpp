//
//  LC203.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/8/25.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *prev = dummyHead;
        while (prev->next) {
            if (prev->next->val == val) {
                prev->next = prev->next->next;
            }
            else {  // 上面走过了，下面放在else里
                prev = prev->next;
            }
        }
        return dummyHead->next;
    }
};

static void LCTester203() {
    
}
