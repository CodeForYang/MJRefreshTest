//
//  UIScrollView+MJExtension.h
//  MJRefreshTest
//
//  Created by 10.12 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (MJExtension)
@property(readonly,nonatomic) UIEdgeInsets mj_inset;

@property(assign,nonatomic) CGFloat mj_insetT;
@property(assign,nonatomic) CGFloat mj_insetB;
@property(assign,nonatomic) CGFloat mj_insetL;
@property(assign,nonatomic) CGFloat mj_insetR;

@property(assign,nonatomic) CGFloat mj_offsetX;
@property(assign,nonatomic) CGFloat mj_offsetY;

@property(assign,nonatomic) CGFloat mj_contentW;
@property(assign,nonatomic) CGFloat mj_contentH;

@end

NS_ASSUME_NONNULL_END
