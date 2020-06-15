//
//  MJRefreshGifHeader.m
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/8.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshGifHeader.h"
@interface MJRefreshGifHeader()
{
    __unsafe_unretained UIImageView *_gifView;
}

/// 所有状态对应的动画图片
@property(nonatomic,strong)NSMutableDictionary *stateImages;

/// 所有状态对应的动画时间
@property(nonatomic,strong)NSMutableDictionary *stateDuration;
@end


@implementation MJRefreshGifHeader

#pragma mark - 懒加载
- (UIImageView *)gifView{
    if (!_gifView) {
        UIImageView *gifView = [[UIImageView alloc]init];
        [self addSubview:_gifView = gifView];
    }
    return _gifView;
}

- (NSMutableDictionary *)stateImages{
    if (!_stateImages) {
        _stateImages = [NSMutableDictionary dictionary];
    }
    return _stateImages;
}

- (NSMutableDictionary *)stateDuration{
    if (!_stateDuration) {
        _stateDuration = [NSMutableDictionary dictionary];
    }
    return _stateDuration;
}


#pragma mark - 公共方法
- (void)setImage:(NSArray *)images duration:(NSTimeInterval)duration forState:(MJRefreshState)state{
    if(images == nil) return;
    
    self.stateImages[@(state)] = images;
    self.stateDuration[@(state)] = @(duration);

    //根据图片设置控件高度
    UIImage *image = [images firstObject];
    if (image.size.height > self.mj_h) {
        self.mj_h = image.size.height;
    }
}

- (void)setImage:(NSArray *)images forState:(MJRefreshState)state{
    [self setImage:images duration:images.count * 0.1 forState:state];
}

#pragma mark - 实现父类的方法
- (void)prepare{
    [super prepare];
    
    //初始化间距
    self.labelLeftInset = 20;
}

- (void)setPullingPercent:(CGFloat)pullingPercent{
    
    [super setPullingPercent:pullingPercent];
    NSArray *images = self.stateImages[@(MJRefreshStateIdle)];
    if(self.state != MJRefreshStateIdle || images.count == 0) return;
    
    //停止动画
    [self.gifView stopAnimating];
    //设置当前需要显示的图片
    NSUInteger index = images.count * pullingPercent;
    if(index >= images.count) index = images.count - 1;
    self.gifView.image = images[index];
}

- (void)placeSubviews{
    
    [super placeSubviews];
    if(self.gifView.constraints.count) return;
    
    self.gifView.frame = self.bounds;
    if (self.stateLabel.hidden && self.lastUpdatedTimeLabel.hidden) {
        self.gifView.contentMode = UIViewContentModeCenter;
    }else{
        self.gifView.contentMode = UIViewContentModeRight;
        CGFloat stateWidth = self.stateLabel.mj_textWidth;
        CGFloat timeWidth = 0.0;
        if (!self.lastUpdatedTimeLabel.hidden) {
            timeWidth = self.lastUpdatedTimeLabel.mj_textWidth;
        }
        CGFloat textWidth = MAX(stateWidth, timeWidth);
        self.gifView.mj_w = self.mj_w * 0.5 - textWidth * 0.5 - self.labelLeftInset;
    }
}

- (void)setState:(MJRefreshState)state{
    
    MJRefreshCheckState
    
    //根据状态做事情
    if (state == MJRefreshStatePulling || state == MJRefreshStateRefreshing) {
        NSArray *images = self.stateImages[@(state)];
        if(images.count == 0) return;
        
        [self.gifView stopAnimating];
        if (images.count == 1) {//单张图片
            self.gifView.image = [images lastObject];
        }else{//多张图片
            self.gifView.animationImages = images;
            self.gifView.animationDuration = [self.stateDuration[@(state)] doubleValue];
            [self.gifView startAnimating];
        }
    }else if(state == MJRefreshStateIdle){
        [self.gifView stopAnimating];
    }
}
@end
