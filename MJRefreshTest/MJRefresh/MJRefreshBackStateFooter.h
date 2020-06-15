//
//  MJRefreshBackStateFooter.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/9.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshBackFooter.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshBackStateFooter : MJRefreshBackFooter

/// 文字距离菊花 箭头的距离
@property(assign,nonatomic) CGFloat labelLeftInset;

/// 显示刷新状态的label
@property(nonatomic,weak,readonly)UILabel *stateLabel;

/// 设置state状态下的文字
/// @param title 文字
/// @param state 状态
- (void)setTitle:(NSString *)title forState:(MJRefreshState)state;

/// 获取state状态下的title
/// @param state 状态
- (NSString *)titleForState:(MJRefreshState)state;
@end

NS_ASSUME_NONNULL_END
