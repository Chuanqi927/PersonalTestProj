//
//  TestManager.m
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/6/29.
//

#import "TestManager.h"
#import "CPPDataTypeTest.hpp"
#import "CPPSampleTestManager.hpp"

@implementation TestManager

+ (instancetype)shareInstance {
    static TestManager *instance;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        instance = [[TestManager alloc] init];
    });
    
    return instance;
}

- (void)runCPPDataTypeTester {
    CPPDataTypeTester::getInstance()->testUnsignedDataTypes();
}

- (void)runCPPDelegateTester {
//    CPPSampleTestManager::getInstance()->log(LogTypeError, "Hello From TestManager");
}

@end
