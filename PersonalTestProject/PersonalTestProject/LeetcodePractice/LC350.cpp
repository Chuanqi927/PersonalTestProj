//
//  LC350.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/1.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // ASSERT nums1 is the larger array
        if (nums1.size() < nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map;
        vector<int> ans;
        for (int& num : nums1) {
            map[num]++;
        }
        for (int& num : nums2) {
            if (map.find(num) != map.end()) {
                ans.push_back(num);
                map[num]--;
                if (map[num] == 0) {
                    map.erase(num);
                }
            }
        }
        return ans;
    }
};
