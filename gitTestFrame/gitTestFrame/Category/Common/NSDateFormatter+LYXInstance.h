//
//  NSDateFormatter+LYXInstance.h
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/16.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDateFormatter (LYXInstance)

+ (id)dateFormatter;

+ (id)dateFormatterWithFormat:(NSString *)dateFormat;

/*
 *默认的日期格式
 *格式：yyyy-MM-dd HH:mm:ss
 */
+ (id)defaultDateFormatter;

@end

NS_ASSUME_NONNULL_END
