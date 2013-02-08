//
// Created by azu on 2013/02/05.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
#import "GAI.h"
// @see http://d.hatena.ne.jp/diveintounlimit/20120922/1348316659
#ifdef DEBUG
#define GA_INIT_TRACKER(ACCOUNT, PERIOD) { \
[GAI sharedInstance].trackUncaughtExceptions = YES; \
[GAI sharedInstance].dispatchInterval = PERIOD; \
[GAI sharedInstance].debug = YES; \
id<GAITracker> tracker = [[GAI sharedInstance] trackerWithTrackingId:ACCOUNT]; \
tracker.useHttps = true; \
}
#else
#define GA_INIT_TRACKER(ACCOUNT, PERIOD) { \
[GAI sharedInstance].trackUncaughtExceptions = YES; \
[GAI sharedInstance].dispatchInterval = PERIOD; \
[GAI sharedInstance].debug = NO; \
id<GAITracker> tracker = [[GAI sharedInstance] trackerWithTrackingId:ACCOUNT]; \
tracker.useHttps = true; \
}
#endif

// クラストラッキング
#define GA_TRACK_CLASS GA_TRACK_PAGE(NSStringFromClass([self class]));
// メソッドトラッキング
#define GA_TRACK_METHOD GA_TRACK_EVENT(NSStringFromClass([self class]), NSStringFromSelector(_cmd), @"", [[NSNumber alloc] initWithInt:-1]);
// ページトラッキング
#define GA_TRACK_PAGE(PAGE) [[[GAI sharedInstance] defaultTracker] trackView:PAGE];

@interface GoogleAnalyticConfig : NSObject

+ (NSString *)trackingId;

@end