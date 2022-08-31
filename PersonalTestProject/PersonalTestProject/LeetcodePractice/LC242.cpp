//
//  LC242.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/8/31.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"


using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charMap;
        for (char ch : s) {
            charMap[ch]++;
        }
        for (char ch : t) {
            charMap[ch]--;
        }
        for (auto &it : charMap) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};
