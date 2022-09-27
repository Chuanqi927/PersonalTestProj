//
//  LC232_MyQueue.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/27.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        int result = outputStack.top();
        outputStack.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        outputStack.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
    
private:
    stack<int> inputStack;
    stack<int> outputStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
