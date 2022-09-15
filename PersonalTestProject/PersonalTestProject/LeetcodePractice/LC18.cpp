//
//  LC18.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/14.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            // 剪枝处理
            if (nums[i]>target && nums[i]>=0 && target>=0) {
                break;
            }
            // 对nums[i] (a)去重
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            for (int j=i+1; j<nums.size(); j++) {
                // 二级剪枝处理
                if (nums[j]+nums[i]>target && nums[j]+nums[i]>=0 && target>=0) {
                    break;
                }
                // 对nums[j] (b)去重
                if (j>i+1 && nums[j]==nums[j-1]) {
                    continue;
                }
                
                // two pointers 找c和d
                int left = j+1, right = nums.size()-1;
                while (left < right) {
                    // 加上强转long防止溢出
                    if ((long)nums[left] + nums[right] + nums[i] + nums[j] < target) {
                        left++;
                    } else if ((long)nums[left] + nums[right] + nums[i] + nums[j] > target) {
                        right--;
                    } else {
                        ret.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        // 去重c和d
                        while (left<right && nums[right]==nums[right-1]) {
                            right--;
                        }
                        while (left<right && nums[left]==nums[left+1]) {
                            left++;
                        }
                        left++;
                        right--;
                    }
                }
                
            }
        }
        return ret;
    }
};
