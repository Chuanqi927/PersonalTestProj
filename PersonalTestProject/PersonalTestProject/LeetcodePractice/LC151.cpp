//
//  LC151.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/17.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution151 {
public:
    void removeExtraSpaceFromStr(string& s) {
        int slow = 0;
        for (int fast=0; fast<s.size(); fast++) {
            if (s[fast] != ' ') {   // 只处理非空格的char
                if (slow != 0) {    // 手动添加一个空格
                    s[slow] = ' ';
                    slow++;
                }
                while (s[fast] != ' ' && fast<s.size()) {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);             // slow的大小即为去除空格之后的大小，会删除slow之后的char
    }

    void reverseString(string& s, int start, int end) {
        if (s.empty()) {
            return;
        }
        int left = start, right = end;
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }
        removeExtraSpaceFromStr(s);
        reverseString(s, 0, s.size()-1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { // 到达空格或者串尾，说明一个单词结束。进行翻转。
                reverseString(s, start, i-1);   // 翻转，注意是左闭右闭 []的翻转。
                start = i + 1; // 更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

static void LCTester151() {
    string input;
    getline(cin, input);
    
    Solution151 obj;
    string output = obj.reverseWords(input);
    
    cout << "reversed words for input : " << input << " is : " << output << endl;
}
