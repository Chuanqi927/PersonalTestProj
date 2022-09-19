//
//  ReverseLeftWords.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/9/19.
//

#include <stdio.h>
#include "../CPP/CPPComUtils.hpp"

using namespace std;

class SolutionRLW1 {
public:
    string reverseLeftWords(string& s, int n) {
        if (s.empty()) {
            return "";
        }
        string subStr = s.substr(0,n-1);
        for (int i=0; i<s.size(); i++) {
            if (i>=n) {
                s[i] = subStr[i-n];
            } else {
                s[i] = s[n+1];
            }
        }
        return s;
    }
};

class SolutionRLW2 {
public:
    string reverseLeftWords(string& s, int n) {
        if (s.empty()) {
            return "";
        }
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

static void reverseLeftWordsTester() {
    string input = "abcdefg";
    int k =2;
    SolutionRLW1 obj1;
    SolutionRLW2 obj2;
    cout << "solution1 output : " << obj1.reverseLeftWords(input, k) << endl;
    cout << "solution2 output : " << obj2.reverseLeftWords(input, k) << endl;
}
