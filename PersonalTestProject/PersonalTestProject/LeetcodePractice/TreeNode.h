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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif /* TreeNode_h */
