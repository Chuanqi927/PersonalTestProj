//
//  TestManager.m
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/6/29.
//

#import "TestManager.h"
#import "CPPBridgeManager.h"
#import "NativeCPPManager.h"
#include "CPPDataTypeTest.hpp"
#include "CPPSampleTestManager.hpp"
#include "LCManager.hpp"

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
//    CPPDataTypeTester::getInstance()->testUnsignedDataTypes();
    CPPDataTypeTester::getInstance()->testPointerDeletion();
}

- (void)runCPPDelegateTester {
    [CPPBridgeManager.sharedInstance setDelegate:NativeCPPManager.sharedInstance];
    
    // C++ log (MGEngine)
    CPPSampleTestManager::getInstance()->log(LogTypeDefault, "Hello From C++");
    
    // native log (MGManager)
    [NativeCPPManager.sharedInstance log:LogTypeDefault msg:@"Hello from Native"];
}

- (void)runOCNilObjTester {
    NSString *testStr = @"1234";
    NSLog(@"testStr length: %lu", testStr.length);
    testStr = nil;
    NSLog(@"testStr length: %lu", testStr.length);
}

- (void)runLCTester {
    LCManager manager;
    manager.runTestCaseForCurrProblem();
}

@end
