//
//  MJRefreshFooter.m
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/8.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshFooter.h"
#include "UIScrollView+MJRefresh.h"

@interface MJRefreshFooter()

@end

@implementation MJRefreshFooter
#pragma mark - 构造方法
+ (instancetype)footerWithRefreshingBlock:(MJRefreshComponentAction)refreshingBlock
{
    MJRefreshFooter *cmp = [[self alloc] init];
    cmp.refreshingBlock = refreshingBlock;
    return cmp;
}
+ (instancetype)footerWithRefreshingTarget:(id)target refreshingAction:(SEL)action
{
    MJRefreshFooter *cmp = [[self alloc] init];
    [cmp setRefreshingTarget:target refreshingAction:action];
    return cmp;
}

#pragma mark - 重写父类方法
- (void)prepare{
    
    [super prepare];
    
    //设置自己的高度
    self.mj_h = MJRefreshFooterHeight;
}

#pragma mark - 公共方法
- (void)endRefreshingWithNoMoreData{
    MJRefreshDispatchAsyncOnMainQueue({
        self.state = MJRefreshStateNoMoreData;
    })
}

- (void)noticeNoMoreData{
    [self endRefreshingWithNoMoreData];
}

- (void)resetNoMoreData{
    MJRefreshDispatchAsyncOnMainQueue({
           self.state = MJRefreshStateIdle;
       })
}

- (void)setAutomaticallyHidden:(BOOL)automaticallyHidden{
    _automaticallyHidden = automaticallyHidden;
}
@end
