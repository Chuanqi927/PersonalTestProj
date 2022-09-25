//
//  LC28.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/25.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    /// 计算前缀表
    /// @param next 前缀表
    /// @param s 模式字符串
    void computeNextArr(int* next, string& s) {
        int i;  // 后缀末尾
        int j = 0; // 前缀末尾，也表示前缀表的数值，即【到j为止的子串最长相等前后缀】的长度，有点像DP
        next[0] = 0;    //
        for (i=1; i<s.size(); ++i) {
            // 前后缀不相同，这里是一个可能存在连续回退的操作，所以用while
            while (j>0 && s[i]!=s[j]) {
                j = next[j-1]; // 向前回退：找前缀表里前一位的值
            }
            // 前后缀相同，最长相等前后缀长度+1
            if (s[i] == s[j]) {
                ++j;
            }
            // 对前缀表赋值
            next[i] = j;
        }
    }
    
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        computeNextArr(next, needle);
        int j = 0;
        for (int i=0; i<haystack.size(); ++i) {
            while (j>0 && haystack[i]!=needle[j]) { // 出现不匹配的情况了
                j = next[j-1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {   // 找全了needle
                // 此时i就是needle的末尾，要return needle在haystack中的index
                return (int)(i-needle.size()+1);
            }
        }
        return -1;
    }
};
