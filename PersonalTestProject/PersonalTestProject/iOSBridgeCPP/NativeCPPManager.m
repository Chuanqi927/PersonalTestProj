//
//  NativeCPPManager.m
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/6.
//

#import "NativeCPPManager.h"

@implementation NativeCPPManager

#pragma mark - CPPBridgeManagerDelegate

- (void)log:(int)logType msg:(NSString *)message {
    if (logType == 0) {         // default log
        NSLog(@"NativeCPPManagerLog Default: %@", message);
    }
    else if (logType == 1) {    // error log
        NSLog(@"NativeCPPManagerLog Error: %@", message);
    }
}

#pragma mark - Public

+ (instancetype)sharedInstance {
    static NativeCPPManager *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[NativeCPPManager alloc] init];
    });
    return instance;
}



@end
