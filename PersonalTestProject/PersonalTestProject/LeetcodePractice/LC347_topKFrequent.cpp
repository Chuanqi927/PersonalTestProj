//
//  LC347_topKFrequent.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/10/6.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> minHeap;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (auto it = map.begin(); it != map.end(); it++) {
            minHeap.push(*it);
            if (minHeap.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                minHeap.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minHeap.top().first;
            minHeap.pop();
        }
        return result;
    }
};
