//
//  LC20_validParentheses.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/28.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> _stack;
        if (s.empty()) return true;
        if (s.size() % 2 != 0) return false;
        for (int i=0; i<s.size(); ++i) {
            if (!_stack.empty()) {
                char top = _stack.top();
                if ((top == '(' && s[i] == ')') ||
                    (top == '[' && s[i] == ']') ||
                    (top == '{' && s[i] == '}')) {
                    _stack.pop();
                }
                else {
                    _stack.push(s[i]);
                }
            }
            else {
                _stack.push(s[i]);
            }
        }
        return _stack.empty();
    }
};
