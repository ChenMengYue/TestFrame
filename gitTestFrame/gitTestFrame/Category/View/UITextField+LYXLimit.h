//
//  UITextField+LYXLimit.h
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/17.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITextField (LYXLimit)

-(void)limitCharacterNumberByLength:(NSInteger)maxLength;
@end


@interface UITextView (LYXLimit)

-(void)limitCharacterNumberByLength:(NSInteger)maxLength;
@end


NS_ASSUME_NONNULL_END
