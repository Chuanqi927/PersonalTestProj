//
//  LC1047_removeDuplicates.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/28.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> _stack;
        if (s.empty()) return s;
        for (int i=0; i<s.size(); ++i) {
            if (!_stack.empty()) {
                char top = _stack.top();
                if (top == s[i]) {
                    _stack.pop();
                    continue;
                }
            }
            _stack.push(s[i]);
        }
        string ans;
        while (!_stack.empty()) {
            ans += _stack.top();
            _stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
