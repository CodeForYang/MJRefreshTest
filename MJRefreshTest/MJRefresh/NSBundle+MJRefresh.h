//
//  NSBundle+MJRefresh.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (MJRefresh)
+ (instancetype)mj_refreshBundle;
+ (UIImage *)mj_arrowImage;
+ (NSString *)mj_localizedStringForKey:(NSString *)key ;
+ (NSString *)mj_localizedStringForKey:(NSString *)key value:( NSString *_Nullable)value;

@end

NS_ASSUME_NONNULL_END
