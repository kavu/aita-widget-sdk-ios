//
//  AAChecklistWidget.m
//  AppInTheAirWidgetSDK
//
//  Created by Sergey Pronin on 10/31/15.
//  Copyright © 2015 App in the Air. All rights reserved.
//

#import "AAChecklistWidget.h"
#import "AppInTheAirWidgetSDK-Swift.h"

@interface AAChecklistWidget()
@property (nonatomic, readwrite) BOOL canBeDisplayed;
@end

@implementation AAChecklistWidget

- (instancetype)initWithDashboard:(Dashboard *)dashboard trip:(Trip *)trip flight:(FlightInfo *)flight {
    self = [super init];
    if (self ) {
        self.dashboard = dashboard;
        self.flight = flight;
        self.trip = trip;
        
        self.canBeDisplayed = YES;
    }
    return self;
}

- (void)configureCell:(UICollectionViewCell *)reusableCell {
    ChecklistWidgetCell *cell = (ChecklistWidgetCell *)reusableCell;
    cell.labelContent.text = @"Objective-C Widget";
}

- (BOOL)canBeHidden {
    return YES;
}

+ (NSString *)widgetType {
    return @"sample";
}

- (UIViewController *)viewController {
    //return any if needed
    return nil;
}

- (NSString *)name {
    return @"SampleWidget";
}

- (CGFloat)cellHeight {
    return 100;
}

- (NSString *)cellIdentifier {
    return @"ChecklistWidgetCell";
}

@end
