//
//  LC454.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/6.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> firstTwoArrSumMap;
        for (int a : nums1) {
            for (int b : nums2) {
                firstTwoArrSumMap[a+b]++;
            }
        }
        int ans = 0;
        for (int c : nums3) {
            for (int d : nums4) {
                int remainder = 0-(c+d);
                if (firstTwoArrSumMap.find(remainder) != firstTwoArrSumMap.end()) {
                    ans+=firstTwoArrSumMap[remainder];
                }
            }
        }
        return ans;
    }
};
