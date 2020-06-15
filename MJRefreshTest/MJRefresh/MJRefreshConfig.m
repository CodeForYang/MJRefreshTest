//
//  MJRefreshConfig.m
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshConfig.h"

@implementation MJRefreshConfig
static MJRefreshConfig *mj_RefreshConfig = nil;
+ (instancetype)defaultConfig{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        mj_RefreshConfig = [[self alloc]init];
    });
    return mj_RefreshConfig;
}
@end
