//
//  NSDate+LYXAttribute.h
//  LYXProjectMethod
//
//  Created by upplus_Cmy on 2020/4/16.
//  Copyright © 2020 upplus_Cmy. All rights reserved.
//


#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, LYXDateCategoryType) {
    LYXDateCategoryType_Year,
    LYXDateCategoryType_Month,
    LYXDateCategoryType_Day,
    LYXDateCategoryType_Hour,
    LYXDateCategoryType_Minute,
};

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (LYXAttribute)

/**
 *  获得当前 NSDate 对象对应的日子
 */
- (NSInteger)dateDay;

/**
 *  获得当前 NSDate 对象对应的月份
 */
- (NSInteger)dateMonth;

/**
 *  获得当前 NSDate 对象对应的年份
 */
- (NSInteger)dateYear;

/*
 * 获得当前 NSDate 对象的前一周时间
*/
-(NSDate *)dateOfPreviousWeekCurDay;
/*
 * 获得当前 NSDate 对象的后一周时间
*/

-(NSDate *)dateOfNextWeekCurDay;

/*
 * 获得当前 NSDate 对象的当前周的第一天
*/
-(NSDate *)dateOfCurrentWeekBeginDay;


/*
 * 获得当前 NSDate 对象的当前周的七天
*/
-(NSArray *)getCurrentWeekDays;


/*一天的起始时间 即 ----/--/-- 00:00:00 */
- (NSDate *) dateAtStartOfDay;




// Decomposing dates
@property (readonly) NSInteger nearestHour;
@property (readonly) NSInteger hour;
@property (readonly) NSInteger minute;
@property (readonly) NSInteger seconds;
@property (readonly) NSInteger day;
@property (readonly) NSInteger month;
@property (readonly) NSInteger week;
@property (readonly) NSInteger weekday;
@property (readonly) NSInteger nthWeekday; // e.g. 2nd Tuesday of the month == 2
@property (readonly) NSInteger year;
@end



@interface NSDate (LYXValidy)

- (BOOL) isWeekend;
- (BOOL) isWorkday;

// Comparing dates
- (BOOL) isSameDate: (NSDate *) aDate;
- (BOOL) isToday;
- (BOOL) isTomorrow;
- (BOOL) isYesterday;
- (BOOL) isSameWeekAsDate: (NSDate *) aDate;
- (BOOL) isThisWeek;
- (BOOL) isNextWeek;
- (BOOL) isLastWeek;
- (BOOL) isSameMonthAsDate: (NSDate *) aDate;
- (BOOL) isThisMonth;
- (BOOL) isSameYearAsDate: (NSDate *) aDate;
- (BOOL) isThisYear;
- (BOOL) isNextYear;
- (BOOL) isLastYear;
- (BOOL) isEarlierThanDate: (NSDate *) aDate;
- (BOOL) isLaterThanDate: (NSDate *) aDate;
- (BOOL) isInFuture;
- (BOOL) isInPast;
@end

//相对于当前时间而言
@interface NSDate (LYXFixed)

+ (NSDate *) dateTomorrow;
+ (NSDate *) dateYesterday;


// Relative dates from the current date
+ (NSDate *) dateWithDaysFromNow: (NSInteger) days;
+ (NSDate *) dateWithDaysBeforeNow: (NSInteger) days;

+ (NSDate *) dateWithHoursFromNow: (NSInteger) dHours;
+ (NSDate *) dateWithHoursBeforeNow: (NSInteger) dHours;

+ (NSDate *) dateWithMinutesFromNow: (NSInteger) dMinutes;
+ (NSDate *) dateWithMinutesBeforeNow: (NSInteger) dMinutes;

@end



@interface NSDate (LYXObtain)
/*昨天*/
-(NSDate *)yesterday;

/*
 *获取相隔多长时间的日期
 * dateType：相隔的类型。天/时/分
 * space：相差的数量
 * space>0 : 表示日期之后
 * space<0 : 表示日期之前
 */
-(NSDate *)getDateBySpace:(NSInteger)space type:(LYXDateCategoryType)dateType;



/*
 *day:相差的天数
 *day>0 : 表示日期之后
 *day<0 : 表示日期之前
 */
-(NSDate *)getDateWithBetweenDays:(NSInteger)day;

/**
 * @method
*
* @brief 获取两个日期之间的天数
 * @param fromDate       起始日期
 * @param toDate         终止日期
* @return    总天数
 */
+ (NSInteger)numberOfDaysWithFromDate:(NSDate *)fromDate toDate:(NSDate *)toDate;

@end


@interface NSDate (LYXCompare)

// Retrieving intervals
- (NSInteger) minutesAfterDate: (NSDate *) aDate;
- (NSInteger) minutesBeforeDate: (NSDate *) aDate;
- (NSInteger) hoursAfterDate: (NSDate *) aDate;
- (NSInteger) hoursBeforeDate: (NSDate *) aDate;
- (NSInteger) daysAfterDate: (NSDate *) aDate;
- (NSInteger) daysBeforeDate: (NSDate *) aDate;

// I have not yet thoroughly tested this
- (NSInteger)distanceInDaysToDate:(NSDate *)anotherDate;

@end


@interface NSDate (LYXFormatter)

/*
*返回标准时间
*dateString格式：@"yyyy-MM-dd"
*/
+(NSDate *)getDateByDefaultFormatterString:(NSString *)dateString;
/*
*返回标准时间UTC :  @"yyyy-MM-dd"
*/
-(NSString *)getDefaultFormatterString;
/*
 *返回标准时间UTC
 *formatter：根据传入的格式，返回对应的时间格式
 */
-(NSString *)getFormatterString:(nullable NSString *)formatter;

-(NSString *)getFormatterString:(nullable NSString *)formatter timeZone:(NSString *)timeZone;


//固定的数据
//距离当前的时间间隔描述
- (NSString *)timeIntervalDescription;
/*精确到分钟的日期描述*/
- (NSString *)minuteDescription;
/*格式化日期描述*/
- (NSString *)formattedDateDescription;
/*标准时间日期描述*/
-(NSString *)formattedTime;


+ (NSDate *)dateWithTimeMilliSecondSince1970:(double)timeIntervalSecond;

- (double)timeIntervalSince1970InMilliSecond ;


+ (NSString *)formattedTimeFromTimeInterval:(long long)time;



@end


NS_ASSUME_NONNULL_END
