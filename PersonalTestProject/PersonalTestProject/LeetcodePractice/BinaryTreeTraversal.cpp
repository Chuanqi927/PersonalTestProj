//
//  BinaryTreeTraversal.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/10/8.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Traversal {
public:
    vector<int> iterativePreorder(TreeNode* head) {
        vector<int> ans;
        stack<TreeNode*> stack;
        if (head == nullptr) return ans;
        stack.push(head);
        while (!stack.empty()) {
            TreeNode *curr = stack.top();
            stack.pop();
            ans.push_back(curr->val);
            if (curr->right) stack.push(curr->right);
            if (curr->left) stack.push(curr->left);
        }
        return ans;
    }
    
    vector<int> iterativeInorder(TreeNode* head) {
        vector<int> ans;
        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur != NULL || !stack.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                stack.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            }
            else {
                cur = stack.top(); // 从栈里弹出的数据，就是要添加的数据
                stack.pop();
                ans.push_back(cur->val);        // 中
                cur = cur->right;               // 右
            }
        }
        return ans;
    }
    
    vector<int> iterativePostorder(TreeNode* head) {
        vector<int> ans;
        stack<TreeNode*> stack;
        if (head == NULL) return ans;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            ans.push_back(node->val);
            if (node->left) stack.push(node->left); // 相对于前序遍历，这更改一下入栈顺序
            if (node->right) stack.push(node->right);
        }
        reverse(ans.begin(), ans.end()); // 将结果反转之后就是左右中的顺序了
        return ans;
    }
    
    void recursivePreorder(TreeNode* head, vector<int>& output) {
        if (head == nullptr) return;
        output.push_back(head->val);
        recursivePreorder(head->left, output);
        recursivePreorder(head->right, output);
    }
    
    void recursiveInorder(TreeNode* head, vector<int>& output) {
        if (head == nullptr) return;
        recursiveInorder(head->left, output);
        output.push_back(head->val);
        recursiveInorder(head->right, output);
    }
    
    void recursivePostorder(TreeNode* head, vector<int>& output) {
        if (head == nullptr) return;
        recursivePostorder(head->left, output);
        recursivePostorder(head->right, output);
        output.push_back(head->val);
    }
    
private:
    TreeNode *root;
};
