//
//  TestManager.h
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/6/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestManager : NSObject

+ (instancetype)shareInstance;

- (void)runCPPDataTypeTester;

@end

NS_ASSUME_NONNULL_END
