//
//  MJRefreshHeader.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/5.
//  Copyright © 2020 10.12. All rights reserved.
//  下拉刷新控件:负责监控用户下拉的状态

#import "MJRefreshComponent.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshHeader : MJRefreshComponent

/// 创建header
/// @param refreshingBlock 回调block
+ (instancetype)headerWithRefreshingBlock:(MJRefreshComponentAction)refreshingBlock;

/// 创建header
/// @param target 创建header的目标类
/// @param action 创建的方法
+ (instancetype)headerWithRefreshingTarget:(id)target refreshingAction:(SEL)action;

/// 这个key用来存储上一次下拉刷新成功的时间
@property(nonatomic,copy)NSString *lastUpdatedTimeKey;

/// 上一次下拉刷新成功的时间
@property(nonatomic,strong,readonly,nullable)NSDate *lastUpdatedTime;

/// 忽略scrollView的contentInset的top
@property(assign,nonatomic) CGFloat ignoredScrollViewContentInsetTop;

/// 默认是关闭状态,如果遇到CollectionVoew的动画异常问题可尝试打开
@property(assign,nonatomic) BOOL isCollectionViewAnimationBug;

@end

NS_ASSUME_NONNULL_END
