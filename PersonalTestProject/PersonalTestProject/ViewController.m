//
//  ViewController.m
//  PersonalTestProject
//
//  Created by mortyxiong on 2022/6/21.
//

#import "ViewController.h"
#import "TestManager.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    NSLog(@"in ViewController");
    
    [TestManager.shareInstance runCPPDataTypeTester];
    
//    [TestManager.shareInstance runCPPDelegateTester];

}


@end
