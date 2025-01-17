//
//  UIColor+LYXHexColor.m
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/15.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//

#import "UIColor+LYXHexColor.h"


@implementation UIColor (LYXHexColor)


+ (UIColor *)colorWithHex:(NSInteger)hexValue
{
    return [self colorWithHex:hexValue alpha:1.0f];
}
+ (UIColor *)colorWithHex:(NSInteger)hexValue alpha:(CGFloat)alphaValue{
    return [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16))/255.0
                           green:((float)((hexValue & 0xFF00) >> 8))/255.0
                            blue:((float)(hexValue & 0xFF))/255.0 alpha:alphaValue];
}


+(UIColor *)colorWithHexString:(NSString *)color{
    return [self colorWithHexString:color alpha:1.0f];
}

+ (UIColor *) colorWithHexString: (NSString *)color alpha: (CGFloat)alpha
{
    NSString *cString = [[color stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString];
    
    // String should be 6 or 8 characters
    if ([cString length] < 6) {
        return [UIColor clearColor];
    }
    // 判断前缀
    if ([cString hasPrefix:@"0X"])
        cString = [cString substringFromIndex:2];
    if ([cString hasPrefix:@"#"])
        cString = [cString substringFromIndex:1];
    if ([cString length] != 6)
        return [UIColor clearColor];
    // 从六位数值中找到RGB对应的位数并转换
    NSRange range;
    range.location = 0;
    range.length = 2;
    //R、G、B
    NSString *rString = [cString substringWithRange:range];
    range.location = 2;
    NSString *gString = [cString substringWithRange:range];
    range.location = 4;
    NSString *bString = [cString substringWithRange:range];
    // Scan values
    unsigned int r, g, b;
    [[NSScanner scannerWithString:rString] scanHexInt:&r];
    [[NSScanner scannerWithString:gString] scanHexInt:&g];
    [[NSScanner scannerWithString:bString] scanHexInt:&b];
    
    return [UIColor colorWithRed:((float) r / 255.0f) green:((float) g / 255.0f) blue:((float) b / 255.0f) alpha:alpha];
}


@end


@implementation UIColor (LYXRandom)

+(UIColor *)colorOfRandom{
    return [UIColor colorWithRed:(arc4random_uniform(256))/255.0 green:(arc4random_uniform(256))/255.0 blue:(arc4random_uniform(256))/255.0 alpha:(arc4random_uniform(256))/255.0];
}

+(UIColor *)colorOfRandomFromRangesColor:(NSArray<UIColor *> *)colors{
    int r = arc4random() % [colors count];
    return [colors objectAtIndex:r];
}


@end
