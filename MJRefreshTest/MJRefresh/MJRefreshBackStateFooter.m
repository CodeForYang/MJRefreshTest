//
//  MJRefreshBackStateFooter.m
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/9.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshBackStateFooter.h"
@interface MJRefreshBackStateFooter()
{
    //显示刷新状态的label
    __unsafe_unretained UILabel *_stateLabel;
}
@property(nonatomic,strong)NSMutableDictionary *stateTitles;
@end

@implementation MJRefreshBackStateFooter
#pragma mark - 懒加载
- (NSMutableDictionary *)stateTitles
{
    if (!_stateTitles) {
        self.stateTitles = [NSMutableDictionary dictionary];
    }
    return _stateTitles;
}

- (UILabel *)stateLabel{
    if (!_stateLabel) {
        [self addSubview:_stateLabel = [UILabel mj_label]];
    }
    return _stateLabel;
}

#pragma mark - 公共方法
- (void)setTitle:(NSString *)title forState:(MJRefreshState)state{
    
    if(title == nil) return;
    self.stateTitles[@(state)] = title;
    self.stateLabel.text = self.stateTitles[@(self.state)];
}

- (NSString *)titleForState:(MJRefreshState)state{
    return self.stateTitles[@(state)];
}


#pragma mark - 重写父类方法
- (void)prepare{
    
    [super prepare];
    
    //初始化间距
    self.labelLeftInset = MJRefreshLabelLeftInset;
    
    //初始化文字
    [self setTitle:[NSBundle mj_localizedStringForKey:MJRefreshBackFooterIdleText] forState:MJRefreshStateIdle];
    [self setTitle:[NSBundle mj_localizedStringForKey:MJRefreshBackFooterPullingText] forState:MJRefreshStatePulling];
    [self setTitle:[NSBundle mj_localizedStringForKey:MJRefreshBackFooterRefreshingText] forState:MJRefreshStateRefreshing];
    [self setTitle:[NSBundle mj_localizedStringForKey:MJRefreshBackFooterNoMoreDataText] forState:MJRefreshStateNoMoreData];

}

- (void)placeSubviews{
    
    [super placeSubviews];
    
    if (self.stateLabel.constraints.count) return;
    
    //状态标签
    self.stateLabel.frame = self.bounds;
}

- (void)setState:(MJRefreshState)state{
    
    MJRefreshCheckState
    
    //设置文字状态
    self.stateLabel.text = self.stateTitles[@(state)];
}
@end
