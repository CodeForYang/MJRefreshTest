//
//  UIView+MJExtension.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (MJExtension)
@property (nonatomic,assign)CGFloat mj_x;
@property (nonatomic,assign)CGFloat mj_y;
@property (nonatomic,assign)CGFloat mj_w;
@property (nonatomic,assign)CGFloat mj_h;
@property (nonatomic,assign)CGSize mj_size;
@property (nonatomic,assign)CGPoint mj_origin;

@end

NS_ASSUME_NONNULL_END
