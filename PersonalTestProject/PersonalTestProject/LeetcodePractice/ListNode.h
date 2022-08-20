#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static void printLinkedList(ListNode *head) {
      while (head != nullptr) {
            if (head->next == nullptr) {
                  std::cout << head->val << std::endl;
            }
            else {
                  std::cout << head->val << "->";
            }
            head = head->next;
      }
}
