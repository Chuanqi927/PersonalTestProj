//
//  ReplaceSpaceInStr.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/17.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int spaceCount = 0;
        int oldSize = s.size();
        for (char& ch : s) {
            if (ch == ' ') {
                spaceCount++;
            }
        }
        s.resize(s.size() + spaceCount*2);
        int newSize = s.size();
        // 从末尾往前填充
        for (int i=newSize-1, j=oldSize-1; j<i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            }
            else {
                s[i] = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i-=2;
            }
        }
        return s;
    }
};
