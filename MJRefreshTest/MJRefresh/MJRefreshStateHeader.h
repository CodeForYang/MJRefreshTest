//
//  MJRefreshStateHeader.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/5.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshStateHeader : MJRefreshHeader
#pragma mark - 刷新时间相关

/// 利用这个block来决定显示的更新时间文字
@property(nonatomic,copy,nullable)NSString *(^lastUpdatedTimeText)(NSDate * _Nullable lastUpdatedTime);
#pragma mark - 为什么是weak???
/// 显示上一次刷新时间的label
@property(nonatomic,weak,readonly)UILabel *lastUpdatedTimeLabel;

#pragma mark - 状态相关

/// 文字距离圈圈、箭头的距离
@property(assign,nonatomic) CGFloat labelLeftInset;

/// 显示刷新状态的Label
@property(nonatomic,weak,readonly)UILabel *stateLabel;

/// 设置state状态下的文字
/// @param title 文字
/// @param state 状态
- (void)setTitle:(NSString *)title forState:(MJRefreshState)state;

@end

NS_ASSUME_NONNULL_END
