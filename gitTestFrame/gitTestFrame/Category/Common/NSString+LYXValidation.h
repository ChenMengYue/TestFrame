//
//  NSString+LYXValidation.h
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/15.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (LYXValidation)

/*验证是否是身份证号*/
-(BOOL)validateIsIDCard;

/*验证是否是数字*/
-(BOOL)validateIsNumber;

/*验证是否是邮箱*/
-(BOOL)validateIsEmail;

/*验证字符串是否只包含fitString中的字符*/
-(BOOL)validateIsFitString:(NSString *)fitString;


@end

@interface NSString (LYXEmoji)

//判断第三方键盘中的表情
-(BOOL)hasEmoji;

/*去除表情*/
-(NSString *)filterByRemoveEmoji;

/*判断是否含有表情符号 yes-有 no-没有*/
-(BOOL)isContainEmoji;

@end


@interface NSString (LXYUrl)


@end



NS_ASSUME_NONNULL_END
