//
//  LC383.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/7.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charCountMap;
        for (auto &ch : magazine) {
            charCountMap[ch]++;
        }
        for (auto &ch : ransomNote) {
            if (charCountMap.find(ch) == charCountMap.end()) {
                return false;
            }
            charCountMap[ch]--;
            if (charCountMap[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        
        int letterCount[26] = {0};
        for (char ch : magazine) {
            letterCount[ch-'a']++;
        }
        for (char ch : ransomNote) {
            letterCount[ch-'a']--;
            if (letterCount[ch-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
