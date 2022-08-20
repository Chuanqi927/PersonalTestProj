//
//  LCManager.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/8/20.
//

#include "LCManager.hpp"
#include <algorithm>
#include <iostream>
#include "LC76.cpp"

void LCManager::testOnProblemNumber(int problemNum) {
    int n =  max(problemNum, 0);
    switch (n) {
        case 76:
            LCTester76();
            break;
            
        default:
            break;
    }
}




