//
//  CPPBridgeManager.m
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/5.
//

#import "CPPBridgeManager.h"
#include "CPPSampleTestManager.hpp"
#include "CPPSampleTestManagerDelegate.hpp"

class CPPSampleTestManagerDelegateIOS : public CPPSampleTestManagerDelegate{
public:
    CPPSampleTestManagerDelegateIOS() {
        
    }
    
    void log(LogType type, std::string message) override {
        NSString *msg = [NSString stringWithUTF8String:message.c_str()];
        [CPPBridgeManager.sharedInstance log:type msg:msg];
    }
};


@interface CPPBridgeManager () {
    CPPSampleTestManagerDelegateIOS *testManagerDelegate;
}
@end


@implementation CPPBridgeManager


#pragma mark - Private

- (CPPSampleTestManagerDelegateIOS*)testManagerDelegate {
    if (!testManagerDelegate) {
        testManagerDelegate = new CPPSampleTestManagerDelegateIOS();
    }
    return testManagerDelegate;
}

- (void)p_setupManagerProtocols {
    CPPSampleTestManager::getInstance()->setDelegate(self.testManagerDelegate);
}



#pragma mark - Public

- (instancetype)init {
    if (self = [super init]) {
        [self p_setupManagerProtocols];
    }
    return self;
}

+ (instancetype)sharedInstance {
    static CPPBridgeManager *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[CPPBridgeManager alloc] init];
    });
    return instance;
}

- (void)log:(int)type msg:(NSString*)message {
    if ([self.delegate respondsToSelector:@selector(log:msg:)]) {
        [self.delegate log:type msg:message];
    }
}


@end
