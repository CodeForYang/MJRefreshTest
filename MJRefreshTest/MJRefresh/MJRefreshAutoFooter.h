//
//  MJRefreshAutoFooter.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/9.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshFooter.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshAutoFooter : MJRefreshFooter
/** 是否自动刷新(默认为YES) */
@property (assign, nonatomic, getter=isAutomaticallyRefresh) BOOL automaticallyRefresh;

@property(assign,nonatomic) CGFloat appearencePercentTriggerAutoRefresh MJRefreshDeprecated("请使用triggerAutomaticallyRefreshPercent属性");

/// 当底部控件出现多少时就自动刷新(默认为1.0,也就是底部控件完全出现时,才会自动刷新)
@property(assign,nonatomic) CGFloat triggerAutomaticallyRefreshPercent;


/// 自动除服次数,默认为1,仅在拖拽scrollView时才生效;如果为-1 ,则为无限触发
@property(nonatomic) NSInteger autoTriggerTimes;
@end

NS_ASSUME_NONNULL_END
