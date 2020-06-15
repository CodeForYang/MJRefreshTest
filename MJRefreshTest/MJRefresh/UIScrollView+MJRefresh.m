//
//  UIScrollView+MJRefresh.m
//  MJRefreshTest
//
//  Created by 10.12 on 2020/6/3.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "UIScrollView+MJRefresh.h"
#import "MJRefreshFooter.h"
#import "MJRefreshHeader.h"

#import <objc/runtime.h>
@implementation UIScrollView (MJRefresh)

#pragma mark - header
static const char MJRefreshHeaderKey = '\0';

- (void)setMj_header:(MJRefreshHeader *)mj_header{
    if (mj_header != self.mj_header) {//由于分类不支持属性操作,所以必须自己重写set/get方法,并进行对象关联
        // 删除旧的，添加新的
        
//        [self.mj_header performSelector:@selector(removeFromSuperview)];
        [self.mj_header removeFromSuperview];

        [self insertSubview:mj_header atIndex:0];
        
        //存储新的
        objc_setAssociatedObject(self, &MJRefreshHeaderKey, mj_header, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
}


- (MJRefreshHeader *)mj_header{
    
    return objc_getAssociatedObject(self, &MJRefreshHeaderKey);
}


#pragma mark - footer
static const char MJRefreshFooterKey = '\0';
- (void)setMj_footer:(MJRefreshFooter *)mj_footer{
    if (mj_footer != self.mj_footer) {
        // 删除旧的，添加新的
        [self.mj_footer removeFromSuperview];
        
        [self insertSubview:mj_footer atIndex:0];
        
        //存储新的
        objc_setAssociatedObject(self, &MJRefreshFooterKey, mj_footer, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

    }

}

- (MJRefreshFooter *)mj_footer{
    return objc_getAssociatedObject(self, &MJRefreshFooterKey);

}

#pragma mark - 过期
- (void)setFooter:(MJRefreshFooter *)footer{
    self.mj_footer = footer;
}

- (void)setHeader:(MJRefreshHeader *)header{
    self.mj_header = header;
}

- (MJRefreshFooter *)footer{
    return self.mj_footer;
}

- (MJRefreshHeader *)header{
    return self.mj_header;
}

#pragma mark - other
- (NSInteger)mj_totalDataCount{
    NSInteger totalCount = 0;
    if ([self isKindOfClass:[UITableView class]]) {
        UITableView *tableView = (UITableView *)self;
        for (NSInteger i = 0; i<tableView.numberOfSections; i++) {
            totalCount += [tableView numberOfRowsInSection:i];
        }
    }else if ([self isKindOfClass:[UICollectionView class]]){
        UICollectionView *collectionView = (UICollectionView *)self;
        for (NSInteger i = 0; i<collectionView.numberOfSections; i++) {
            totalCount += [collectionView numberOfItemsInSection:i];
        }
    }
    
    
    
    return totalCount;
}
@end
