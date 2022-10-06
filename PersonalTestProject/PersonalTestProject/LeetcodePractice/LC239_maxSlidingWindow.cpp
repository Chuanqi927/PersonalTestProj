//
//  LC239_maxSlidingWindow.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/10/6.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;


/// 单调递增队列
class myMaxQueue {
public:
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value) {
        if (!_queue.empty() && value == _queue.front()) {
            _queue.pop_front();
        }
    }
    
    // 如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止
    void push(int value) {
        while (!_queue.empty() && value > _queue.back()) {
            _queue.pop_back();
        }
        _queue.push_back(value);
    }
    
    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front() {
        return _queue.front();
    }
private:
    deque<int> _queue;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        myMaxQueue maxQ;
        
        for (int i = 0; i < k; i++) { // 先将第一个window的元素放进队列
            maxQ.push(nums[i]);
        }
        ans.push_back(maxQ.front()); // 第一个window的最大值放到ans中
        for (int i = k; i < nums.size(); i++) {
            maxQ.pop(nums[i - k]);          // 滑动窗口移除最前面元素
            maxQ.push(nums[i]);             // 滑动窗口前加入最后面的元素
            ans.push_back(maxQ.front());    // 记录对应的最大值
        }
        return ans;
    }
};
