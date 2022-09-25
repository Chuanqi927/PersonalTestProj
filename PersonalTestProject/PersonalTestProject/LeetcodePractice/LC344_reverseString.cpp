//
//  LC344.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/15.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        int left = 0, right = s.size()-1;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return;
    }
};
