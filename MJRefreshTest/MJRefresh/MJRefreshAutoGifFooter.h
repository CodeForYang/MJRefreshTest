//
//  MJRefreshAutoGifFooter.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/9.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshAutoStateFooter.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshAutoGifFooter : MJRefreshAutoStateFooter
@property (weak, nonatomic, readonly) UIImageView *gifView;

/** 设置state状态下的动画图片images 动画持续时间duration*/
- (void)setImages:(NSArray *)images duration:(NSTimeInterval)duration forState:(MJRefreshState)state;
- (void)setImages:(NSArray *)images forState:(MJRefreshState)state;


@end

NS_ASSUME_NONNULL_END
