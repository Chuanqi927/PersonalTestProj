//
//  LC1209_removeDuplicates.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/28.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> counts;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                counts.push(1);
            }
            else {
                counts.top()++;
                if (counts.top() == k) {
                    counts.pop();
                    s.erase(i - k + 1, k);
                    i = i - k;
                }
            }
        }
        return s;
    }
};
