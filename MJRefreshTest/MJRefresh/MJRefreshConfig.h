//
//  MJRefreshConfig.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshConfig : NSObject

/// 默认使用的语言版本,默认为nil,讲随系统的语言自动改变
@property(nonatomic,strong,nullable)NSString *languageCode;

/// 返回单例
+ (instancetype)defaultConfig;

- (instancetype)init NS_UNAVAILABLE;//不允许外界用init方式创建这个类
+ (instancetype)new NS_UNAVAILABLE;//不允许外界用new方式创建这个类
@end

NS_ASSUME_NONNULL_END
