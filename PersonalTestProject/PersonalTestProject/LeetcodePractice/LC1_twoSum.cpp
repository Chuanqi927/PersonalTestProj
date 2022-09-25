//
//  LC1.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/5.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap;
        for (int idx = 0; idx<nums.size(); idx++) {
            int remainder = target - nums[idx];
            auto it = numIndexMap.find(remainder);
            if (it != numIndexMap.end()) {
                return {idx, it->second};
            }
            numIndexMap.insert(pair<int, int>(nums[idx], idx));
        }
        return vector<int>();
    }
};


