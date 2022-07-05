//
//  CPPSampleTestManager.hpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/5.
//

#ifndef CPPSampleTestManager_hpp
#define CPPSampleTestManager_hpp

#include <stdio.h>
#include <string>
#include "CPPSampleTestManagerDelegate.hpp"

typedef enum LogType : int {
    LogTypeDefault = 0,
    LogTypeNotice = LogTypeDefault,
    LogTypeError = 1,
};

class CPPSampleTestManager {
public:
    static CPPSampleTestManager* getInstance();
    static CPPSampleTestManagerDelegate* getDelegate();
    void setDelegate(CPPSampleTestManagerDelegate *delegate);
    
    void log(LogType type, std::string message);
    
private:
    CPPSampleTestManager();
    CPPSampleTestManagerDelegate *delegate;
    
};

#endif /* CPPSampleTestManager_hpp */
