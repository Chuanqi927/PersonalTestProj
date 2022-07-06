//
//  NativeCPPManager.h
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/6.
//

#import <Foundation/Foundation.h>
#import "CPPBridgeManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface NativeCPPManager : NSObject <CPPBridgeManagerDelegate>

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
