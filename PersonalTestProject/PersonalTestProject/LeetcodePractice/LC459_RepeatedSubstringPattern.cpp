//
//  LC459.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/25.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution1_AppendString {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        // 去掉t中本来的两个s
        t.erase(t.begin());
        t.erase(t.end()-1);
        if (t.find(s) != string::npos) {
            return true;
        }
        return false;
    }
};

class Solution2_KMP {
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
    
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int length = s.size();
        int next[length];
        computeNextArr(next, s);
        if (next[length-1] != 0 &&           // 有最长相等前后缀
            length % (length - next[length-1]) == 0) { // 且size是最长相等前后缀的长度的倍数)
            return true;
        }
        return false;
    }
};
