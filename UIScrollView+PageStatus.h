//
//  UIScrollView+PageStatus.h
//  催客网项目
//
//  Created by nate on 16/7/22.
//  Copyright © 2016年 TonyLi. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger,PageStatus) {
    
    PageStatusLoading,
    PageStatusError,
    PageStatusSucceed
};

typedef void(^EmptyViewTapBlock)();

@interface UIScrollView (PageStatus)<DZNEmptyDataSetSource, DZNEmptyDataSetDelegate>

/**
 *  当前页面状态
 */
@property (nonatomic, assign) PageStatus currentPageStatus;

/**
 *  如果请求成功，空数据，显示提示
 */
@property (nonatomic, strong) NSString *succeedEmptyStr;

/**
 *  如果请求成功，空数据，显示的图片
 */
@property (nonatomic ,strong) UIImage *succeedEmptyImage;

/**
 *  空页面点击，刷新block
 */
@property (nonatomic, copy) EmptyViewTapBlock emptyViewTapBlock;

@end
