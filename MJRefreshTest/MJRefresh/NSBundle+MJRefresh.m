//
//  NSBundle+MJRefresh.m
//  MJRefreshTest
//
//  Created by 易家杨 on 2020/6/4.
//  Copyright © 2020 10.12. All rights reserved.
//

#import "NSBundle+MJRefresh.h"
#import "MJRefreshComponent.h"
#import "MJRefreshConfig.h"
@implementation NSBundle (MJRefresh)

+ (instancetype)mj_refreshBundle{
    static NSBundle *refreshBundle = nil;
    if (refreshBundle == nil) {
        //这里不使用mainBundle时为了适配pod 1.x和0.x
        //
         refreshBundle = [NSBundle bundleWithPath:[[NSBundle bundleForClass:NSClassFromString(@"MJRefreshComponent")] pathForResource:@"MJRefresh" ofType:@"bundle"]];
    }
    
    return refreshBundle;
}

+ (UIImage *)mj_arrowImage{
    static UIImage *arrowImage = nil;
    if (arrowImage == nil) {
        arrowImage = [[UIImage imageWithContentsOfFile:[[self mj_refreshBundle] pathForResource:@"arrow@2x" ofType:@"png"]]  imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
    }
    
    return arrowImage;
}


+ (NSString *)mj_localizedStringForKey:(NSString *)key{
    return [self mj_localizedStringForKey:key value:nil];
}

+ (NSString *)mj_localizedStringForKey:(NSString *)key value:(NSString *)value{
    static NSBundle *bundle = nil;
    if (bundle == nil) {
        NSString *language = MJRefreshConfig.defaultConfig.languageCode;
        //如果配置中没有配置语言
        if(!language){
            //(iOS获取的语言字符串比较不稳定) 目前框架只处理en,zh-Hans,zh-Hant三种情况,其他情况按照系统默认处理
            language = [NSLocale preferredLanguages].firstObject;
        }
        
        if ([language hasPrefix:@"en"]) {//英文
            language = @"en";
        }else if ([language hasPrefix:@"zh"]){//中文
            if ([language rangeOfString:@"Hans"].location != NSNotFound) {
                language = @"zh-Hans";//简体中文
            }else{//zh-Hant\zh-HK\zh-TW
                language = @"zh-Hant";//繁体
            }
        }else if([language hasPrefix:@"ko"]){//Korea-韩语
            language = @"ko";
        }else if ([language hasPrefix:@"ru"]){//Russia-俄语
            language = @"ru";
        }else if ([language hasPrefix:@"uk"]){//UK-英语
            language = @"uk";
        }else {
            language = @"en";
        }
        //从MJRefresh.bundle中查找资源
        bundle = [NSBundle bundleWithPath:[[NSBundle mj_refreshBundle] pathForResource:language ofType:@"lproj"]];
    }
    value = [bundle localizedStringForKey:key value:value table:nil];
    return [[NSBundle mainBundle] localizedStringForKey:key value:value table:nil];
}

@end
