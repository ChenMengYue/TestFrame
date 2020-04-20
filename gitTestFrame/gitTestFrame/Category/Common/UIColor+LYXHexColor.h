//
//  UIColor+LYXHexColor.h
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/15.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (LYXHexColor)

+ (UIColor *)colorWithHex:(NSInteger)hexValue;

+ (UIColor *)colorWithHex:(NSInteger)hexValue alpha:(CGFloat)alphaValue;

// 颜色转换：iOS中（以#开头）十六进制的颜色转换为UIColor(RGB)
+(UIColor *)colorWithHexString:(NSString *)color;

+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;



@end


@interface UIColor (LYXRandom)

+(UIColor *)colorOfRandom;

+(UIColor *)colorOfRandomFromRangesColor:(NSArray<UIColor *> *)colors;

@end
NS_ASSUME_NONNULL_END
