//
//  MJRefreshBackNormalFooter.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/9.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshBackStateFooter.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshBackNormalFooter : MJRefreshBackStateFooter

@property (weak, nonatomic, readonly) UIImageView *arrowView;
@property (weak, nonatomic, readonly) UIActivityIndicatorView *loadingView;

/** 菊花的样式 */
@property (assign, nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle MJRefreshDeprecated("first deprecated in 3.2.2 - Use `loadingView` property");

@end

NS_ASSUME_NONNULL_END
