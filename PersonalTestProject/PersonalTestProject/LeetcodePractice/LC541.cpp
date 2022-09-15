//
//  LC541.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/15.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    // 左闭右闭区间的reverse
    void reverseStr(string &strRef, int start, int end) {
        if (strRef.empty()) {
            return;
        }
        int i = start, j = end;
        while (i < j) {
            char temp = strRef[i];
            strRef[i] = strRef[j];
            strRef[j] = temp;
            i++;
            j--;
        }
        return;
    }
    
    string reverseStr(string s, int k) {
        // 每2k个char进一次
        for (int i=0; i<s.size(); i+=2*k) {
            if (i + k < s.size()) {
                // reverse 前k个char
                reverseStr(s, i, i+k-1);
            }
            else {
                // reverse 到末尾
                reverseStr(s, i, (int)s.size()-1);
            }
        }
        return s;
    }
};
