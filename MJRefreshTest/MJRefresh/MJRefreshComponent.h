//
//  MJRefreshComponent.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MJRefreshConst.h"
#import "UIView+MJExtension.h"
#import "UIScrollView+MJExtension.h"
#import "UIScrollView+MJRefresh.h"
#import "NSBundle+MJRefresh.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger ,MJRefreshState) {
    MJRefreshStateIdle = 1,//普通闲置状态
    MJRefreshStatePulling,//松开就可以刷新的状态
    MJRefreshStateRefreshing,//正在刷新的状态
    MJRefreshStateWillRefresh,//即将刷新的状态
    MJRefreshStateNoMoreData//所有数据都加载完毕,没有更多数据
};
/** 进入刷新状态的回调*/
typedef void (^MJRefreshComponentRefreshingBlock)(void) MJRefreshDeprecated("first deprecated in 3.3.0 - Use `MJRefreshComponentAction` instead");

/** 开始刷新后的回调(进入刷新状态后的回调)*/
typedef void (^MJRefreshComponentBeginRefreshingCompletionBlock)(void) MJRefreshDeprecated("first deprecated in 3.3.0 - Use `MJRefreshComponentAction` instead");
;
/** 结束刷新后的回调*/
typedef void (^MJRefreshComponentEndRefreshingCompletionBlock)(void)MJRefreshDeprecated("first deprecated in 3.3.0 - Use `MJRefreshComponentAction` instead");

/** 刷新用到的回调类型*/
typedef void (^MJRefreshComponentAction)(void);

@interface MJRefreshComponent : UIView{
    /** 记录scrollView刚开始的inset*/
    UIEdgeInsets _scrollViewOriginalInset;
    /**父控件*/
    __weak UIScrollView *_scrollView;
}

#pragma mark - 刷新回调
/** 正在刷新的回调 */
@property (copy, nonatomic, nullable) MJRefreshComponentAction refreshingBlock;
/** 设置回调对象和回调方法 */
- (void)setRefreshingTarget:(id)target refreshingAction:(SEL)action;

/** 回调对象 */
@property (weak, nonatomic) id refreshingTarget;
/** 回调方法 */
@property (assign, nonatomic) SEL refreshingAction;
/** 触发回调（交给子类去调用） */
- (void)executeRefreshingCallback;


#pragma mark - 刷新状态控制

/// 进入刷新状态
- (void)beginRefreshing;
/// 刷新block
/// @param completionBlock block回调
- (void)beginRefreshingWithCompletionBlock:(void (^)(void))completionBlock;
/// 开始刷新后的回调(进入刷新状态后的回调)
@property(nonatomic,copy)MJRefreshComponentAction beginRefreshingCompletionBlock;
/// 带动画的结束刷新回调
@property(nonatomic,copy)MJRefreshComponentAction endRefreshingAnimateCompletionBlock MJRefreshDeprecated("first deprecated in 3.3.0 - Use `endRefreshingAnimationBeginAction` instead");
@property(nonatomic,copy)MJRefreshComponentAction endRefreshingAnimationBeginAction;
/// 结束刷新的回调
@property(nonatomic,copy)MJRefreshComponentAction endRefreshingCompletionBlock;

/// 结束刷新状态
- (void)endRefreshing;
- (void)endRefreshingWithCompletionBlock:(void (^)(void))completionBlock;

/// 是否正在刷新
@property(assign,nonatomic,readonly,getter=isRefreshing) BOOL refreshing;

/// 刷新状态 一般交给子类 内部实现
@property(assign,nonatomic) MJRefreshState state;

#pragma mark - 交给子类们去访问

/// 记录scrollView刚开始的inset
@property(assign,nonatomic,readonly) UIEdgeInsets scrollViewOriginalInset;

/// 父控件 - 弱引用
@property(weak,nonatomic,readonly) UIScrollView *scrollView;

#pragma mark - 交给子类们去实现
/// 初始化
- (void)prepare NS_REQUIRES_SUPER;
/// 摆放子控件frame
- (void)placeSubviews NS_REQUIRES_SUPER;

/// scrollViewContentOffset 改变的时候调用
/// @param change 改变的字典
- (void)scrollViewContentOffsetDidChange:(nullable NSDictionary *)change NS_REQUIRES_SUPER;

/// scrollViewContentSize 改变的时候调用
/// @param change 改变的字典
- (void)scrollViewContentSizeDidChange:(nullable NSDictionary *)change NS_REQUIRES_SUPER;

/// scrollViewContentState 改变的时候调用
/// @param change 改变的字典
- (void)scrollViewPanStateDidChange:(nullable NSDictionary *)change NS_REQUIRES_SUPER;


#pragma mark - 其他
/// 拉拽的百分比(交给子类重写)
@property(assign,nonatomic) CGFloat pullingPercent;

/// 根据拖拽比例 - 自动切换透明度
@property(assign,nonatomic,getter=isAutoChangeAlpha) BOOL autoChangeAlpha MJRefreshDeprecated("请使用automaticallyChangeAlpha属性");
@property(assign,nonatomic,getter=isAutomaticallyChangeAlpha) BOOL automaticallyChangeAlpha;
@end

@interface UILabel(MJRefresh)
+ (instancetype)mj_label;
- (CGFloat)mj_textWidth;
@end
NS_ASSUME_NONNULL_END
