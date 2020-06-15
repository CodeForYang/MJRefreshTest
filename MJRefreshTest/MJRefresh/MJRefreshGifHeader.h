//
//  MJRefreshGifHeader.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/8.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshStateHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshGifHeader : MJRefreshStateHeader
@property(nonatomic,weak,readonly) UIImageView *gifView;

/// 设置state状态下的动画图片images 动画持续时间
/// @param images 动图
/// @param duration  动画持续时间
/// @param state 状态
- (void)setImage:(NSArray *)images duration:(NSTimeInterval)duration forState:(MJRefreshState)state;
- (void)setImage:(NSArray *)images forState:(MJRefreshState)state;

@end

NS_ASSUME_NONNULL_END
