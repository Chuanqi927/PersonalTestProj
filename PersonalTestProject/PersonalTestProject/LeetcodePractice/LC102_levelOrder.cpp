//
//  LC102_levelOrder.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/10/8.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            vector<int> currLevel;
            int size = (int)que.size();
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            for (int i=0; i<size; ++i) {
                TreeNode *curr = que.front();
                que.pop();
                currLevel.push_back(curr->val);
                if (curr->left) {
                    que.push(curr->left);
                }
                if (curr->right) {
                    que.push(curr->right);
                }
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};

class Solution2_recursion {
public:
    void order(TreeNode* cur, vector<vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth + 1);
        order(cur->right, result, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};
