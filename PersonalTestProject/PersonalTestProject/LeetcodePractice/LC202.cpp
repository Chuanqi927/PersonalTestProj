//
//  LC202.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/4.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class Solution {
public:
    int computeSquareSum(int n) {
        int ans = 0;
        while (n > 0) {
            int digit = n % 10;
            ans += digit * digit;
            n = n / 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n!=1 && set.find(n)==set.end()) {
            set.insert(n);
            n = computeSquareSum(n);
        }
        return n==1;
    }
};
