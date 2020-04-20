//
//  NSString+LYXAttribution.h
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/15.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (LYXAttribution)

-(NSMutableAttributedString *)getAttributeStyleByTextAlignment:(NSTextAlignment)alignment font:(UIFont *)font color:(UIColor *)textColor lineSpace:(float)lineSpace textSpace:(float)textSpace;

-(NSMutableAttributedString *)getAttributeStyleByTextFont:(UIFont *)font color:(UIColor *)textColor lineSpace:(float)lineSpace textSpace:(float)textSpace;

-(CGSize)getHeightOfAttrTextByTextFont:(UIFont *)font color:(UIColor *)textColor lineSpace:(float)lineSpace textSpace:(float)textSpace width:(float)textWidth;

@end


@interface NSString (LYXSize)

-(CGFloat)getWidthWithHeight:(CGFloat)height font:(UIFont *)font;

-(CGFloat)getHeightWithWidth:(CGFloat)width font:(UIFont *)font;
@end




NS_ASSUME_NONNULL_END
