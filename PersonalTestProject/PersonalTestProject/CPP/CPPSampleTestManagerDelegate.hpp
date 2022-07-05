//
//  CPPSampleTestManagerDelegate.hpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/5.
//

#ifndef CPPSampleTestManagerDelegate_hpp
#define CPPSampleTestManagerDelegate_hpp

#include <stdio.h>
#include <string>

enum LogType : int;

class CPPSampleTestManagerDelegate {
public:
    virtual void log(LogType type, std::string message) = 0;
};
#endif /* CPPSampleTestManagerDelegate_hpp */
