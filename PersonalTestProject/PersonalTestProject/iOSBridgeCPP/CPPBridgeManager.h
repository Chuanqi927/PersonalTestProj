//
//  CPPBridgeManager.h
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

enum LogType : int;

@protocol CPPBridgeManagerDelegate <NSObject>

@required
- (void)log:(int)logType msg:(NSString*)message;

@end

@interface CPPBridgeManager : NSObject <CPPBridgeManagerDelegate>

@property (nonatomic, weak) id<CPPBridgeManagerDelegate> delegate;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
