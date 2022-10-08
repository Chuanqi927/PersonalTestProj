//
//  TreeNode.h
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/10/8.
//

#ifndef TreeNode_h
#define TreeNode_h

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif /* TreeNode_h */
