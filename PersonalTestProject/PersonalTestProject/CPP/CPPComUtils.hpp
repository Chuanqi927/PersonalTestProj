//
//  CPPComUtils.hpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/08/23.
//

#ifndef CPPComUtils_hpp
#define CPPComUtils_hpp

#include <stdio.h>
#include <vector>
#include "ListNode.h"
#include <unordered_map>
#include <unordered_set>

namespace CPPComUtils {

//MARK: Vector
void printVector(std::vector<int> &input);
std::vector<int> generateRandomVectorOfSize(int size);
std::vector<int> generateRandomVector();

//MARK: LinkedList
void printLinkedList(ListNode *head);

}



#endif /* CPPComUtils_hpp */
