//
//  CPPSampleTestManager.cpp
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/5.
//

#include "CPPSampleTestManager.hpp"
#include <iostream>

static CPPSampleTestManager* sharedManager = nullptr;

#pragma mark - Private

CPPSampleTestManager::CPPSampleTestManager() {
    std::cout << "CPPSampleTestManager Default Constructor called" << std::endl;
}


#pragma mark - Public

CPPSampleTestManager* CPPSampleTestManager::getInstance() {
    if (sharedManager == nullptr) {
        sharedManager = new CPPSampleTestManager();
    }
    return sharedManager;
}

CPPSampleTestManagerDelegate* CPPSampleTestManager::getDelegate() {
    CPPSampleTestManagerDelegate *delegate = CPPSampleTestManager::getInstance()->delegate;
    assert(delegate);
    return delegate;
}

void CPPSampleTestManager::setDelegate(CPPSampleTestManagerDelegate *delegate) {
    assert(delegate);
    CPPSampleTestManager::getInstance()->delegate = delegate;
}

void CPPSampleTestManager::log(LogType type, std::string message) {
    if (message.size() <= 0) {
        return;
    }
    CPPSampleTestManager::getDelegate()->log(type, message);
}
