//
//  LC15.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/8.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution_hash {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // sort默认升序
        sort(nums.begin(), nums.end());
        
        // a = nums[i]
        // b = nums[j]
        // c = 0-a-b
        for (int i=0; i<nums.size(); i++) {
            // 如果sort之后nums[i]就大于0，那后面肯定不会有满足条件的元素
            if (nums[i] > 0) {
                break;
            }
            // 去重a
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            unordered_set<int> set;
            for (int j=i+1; j<nums.size(); j++) {
                // 去重b
                if (j > i + 2 &&
                    nums[j] == nums[j-1] &&
                    nums[j-1] == nums[j-2]) {
                    continue;
                }
                int remainder =  0 - (nums[i] + nums[j]);
                if (set.find(remainder) != set.end()) {
                    ans.push_back({nums[i], nums[j], remainder});
                    // 去重c
                    set.erase(remainder);
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) {
                return ans;
            }
            // 去重a
            // 错误的方法：如果第一个元素就重复，会漏掉
//            if (nums[i] == nums[i+1]) {
//                continue;
//            }
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int left = i+1, right = nums.size()-1;
            while (left < right) {
                // 去重b和c如果放在这里，{0，0，0} 的情况，可能直接导致 right<=left 了，从而漏掉了 {0,0,0} 这种三元组
                if (nums[i]+nums[left]+nums[right] > 0) {
                    right--;
                }
                else if (nums[i]+nums[left]+nums[right] < 0) {
                    left++;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 去重b和c应该放在找到一个合理ans之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    // 找到合理tuple，移动指针
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
