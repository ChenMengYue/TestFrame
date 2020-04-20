//
//  NSString+LYXAttribution.m
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/15.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//

#import "NSString+LYXAttribution.h"

@implementation NSString (LYXAttribution)

-(NSMutableAttributedString *)getAttributeStyleByTextAlignment:(NSTextAlignment)alignment font:(UIFont *)font color:(UIColor *)textColor lineSpace:(float)lineSpace textSpace:(float)textSpace{
    
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:self];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    if (alignment) {
        [paragraphStyle setAlignment:alignment];//调整行间距

    }
    if (lineSpace) {
        [paragraphStyle setLineSpacing:lineSpace];//调整行间距
    }
    if (textSpace) {
        [attributedString addAttribute:NSKernAttributeName value:@(textSpace) range:NSMakeRange(0, [self length])];
    }
    if (font) {
        [attributedString addAttribute:NSFontAttributeName value:font range:NSMakeRange(0, [self length])];
    }
    
    if (textColor) {
        [attributedString addAttribute:NSForegroundColorAttributeName value:textColor range:NSMakeRange(0, [self length])];
        
    }
    [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, [self length])];
    return attributedString;
}

-(NSMutableAttributedString *)getAttributeStyleByTextFont:(UIFont *)font color:(UIColor *)textColor lineSpace:(float)lineSpace textSpace:(float)textSpace{
    
    return [self getAttributeStyleByTextAlignment:NSTextAlignmentCenter font:font color:textColor lineSpace:lineSpace textSpace:textSpace];
}

-(CGSize)getHeightOfAttrTextByTextFont:(UIFont *)font color:(UIColor *)textColor lineSpace:(float)lineSpace textSpace:(float)textSpace width:(float)textWidth{
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    if (lineSpace) {
        [paragraphStyle setLineSpacing:lineSpace];//调整行间距
    }
    NSDictionary *attrDic= @{NSFontAttributeName:font,NSParagraphStyleAttributeName:paragraphStyle,NSKernAttributeName:@(textSpace),NSForegroundColorAttributeName:textColor};
    
    CGSize lastSize= [self boundingRectWithSize:CGSizeMake(textWidth, MAXFLOAT) options:(NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingTruncatesLastVisibleLine) attributes:attrDic context:nil].size;
    
    return lastSize;
    
}

@end



@implementation NSString (LYXSize)


-(CGFloat)getWidthWithHeight:(CGFloat)height font:(UIFont *)font
{
    CGRect rect = [self boundingRectWithSize:CGSizeMake(MAXFLOAT, height)
                                     options:NSStringDrawingUsesLineFragmentOrigin
                                  attributes:@{NSFontAttributeName:font}
                                     context:nil];
    return rect.size.width;
}

-(CGFloat)getHeightWithWidth:(CGFloat)width  font:(UIFont *)font{
    CGRect rect = [self boundingRectWithSize:CGSizeMake(width, MAXFLOAT)
                                     options:NSStringDrawingUsesLineFragmentOrigin
                                  attributes:@{NSFontAttributeName:font}
                                     context:nil];
    return rect.size.height;
}


@end
