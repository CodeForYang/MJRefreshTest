//
//  MJRefreshFooter.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/8.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshFooter : MJRefreshComponent

/// 析构函数
/// @param refreshingBlock action block
+ (instancetype)footerWithRefreshingBlock:(MJRefreshComponentAction)refreshingBlock;
+ (instancetype)footerWithRefreshingTarget:(id)target refreshingAction:(SEL)action;


/// 没有更多数据
- (void)endRefreshingWithNoMoreData;
- (void)noticeNoMoreData MJRefreshDeprecated("使用endRefreshingWithNoMoreData");

/// 重置没有更多的数据(消除没有更多数据的状态)
- (void)resetNoMoreData;

/// 忽略scrollView的contentInset的botton
@property(assign,nonatomic) CGFloat ignoredScrollViewContentInsetBottom;

/** 自动根据有无数据来显示和隐藏（有数据就显示，没有数据隐藏。默认是NO） */
@property (assign, nonatomic, getter=isAutomaticallyHidden) BOOL automaticallyHidden MJRefreshDeprecated("已废弃此属性，开发者请自行控制footer的显示和隐藏");
@end

NS_ASSUME_NONNULL_END
