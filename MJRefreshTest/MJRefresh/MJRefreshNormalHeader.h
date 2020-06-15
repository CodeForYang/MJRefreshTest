//
//  MJRefreshNormalHeader.h
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/8.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "MJRefreshStateHeader.h"

NS_ASSUME_NONNULL_BEGIN

@interface MJRefreshNormalHeader : MJRefreshStateHeader
@property(nonatomic,weak,readonly)UIImageView *arrowView;
@property(nonatomic,weak,readonly)UIActivityIndicatorView *loadingView;


@property(assign,nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle MJRefreshDeprecated("first deprecated in 3.2.2 - Use `loadingView` property");
@end

NS_ASSUME_NONNULL_END
