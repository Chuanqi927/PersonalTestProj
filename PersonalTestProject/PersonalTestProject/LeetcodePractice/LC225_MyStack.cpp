//
//  LC225_MyStack.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/28.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        _queue.push(x);
    }
    
    int pop() {
        int length = _queue.size();
        // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
        for (int i=0; i<length-1; ++i) {
            _queue.push(_queue.front());
            _queue.pop();
        }
        // 此时的front就是原先的末尾
        int result = _queue.front();
        _queue.pop();
        return result;
    }
    
    int top() {
        return _queue.back();
    }
    
    bool empty() {
        return _queue.empty();
    }
private:
    queue<int> _queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
