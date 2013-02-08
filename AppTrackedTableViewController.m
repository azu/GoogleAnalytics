//
// Created by azu on 2013/02/05.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import "AppTrackedTableViewController.h"
#import "GoogleAnalyticConfig.h"


@implementation AppTrackedTableViewController {

}
- (void)viewDidLoad {
    [super viewDidLoad];
    GA_TRACK_CLASS;
}
@end