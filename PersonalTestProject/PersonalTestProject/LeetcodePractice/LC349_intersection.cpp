//
//  LC349.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/1.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> resultSet;   // 结果用set存储，可以去重
        unordered_set<int> set;
        for (int num : nums1) {
            set.insert(num);
        }
        for (int num : nums2) {
            if (set.find(num) != set.end()) {
                resultSet.insert(num);
            }
        }
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
