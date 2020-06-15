//
//  UIScrollView+MJRefresh.h
//  MJRefreshTest
//
//  Created by 10.12 on 2020/6/3.
//  Copyright © 2020 10.12. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MJRefreshConst.h"

@class MJRefreshHeader, MJRefreshFooter;

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (MJRefresh)

/// 上拉刷新控件
@property (nonatomic,strong,nullable)MJRefreshFooter * mj_footer;

@property (strong, nonatomic, nullable) MJRefreshFooter *footer MJRefreshDeprecated("使用mj_footer");


/// 下拉刷新控件
@property (nonatomic,strong,nullable)MJRefreshHeader *mj_header;

@property (nonatomic,strong,nullable)MJRefreshHeader *header;


#pragma mark - other
- (NSInteger)mj_totalDataCount;
@end

NS_ASSUME_NONNULL_END
