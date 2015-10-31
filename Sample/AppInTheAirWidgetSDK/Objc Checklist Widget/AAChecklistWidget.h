//
//  AAChecklistWidget.h
//  AppInTheAirWidgetSDK
//
//  Created by Sergey Pronin on 10/31/15.
//  Copyright © 2015 App in the Air. All rights reserved.
//

@import UIKit;
@import WidgetSDK;

NS_ASSUME_NONNULL_BEGIN

@interface AAChecklistWidget : NSObject <TripWidget>

@property (nonatomic, strong) Trip *trip;
@property (nonatomic, strong) FlightInfo *flight;
@property (nonatomic, weak) Dashboard *dashboard;

@property (nonatomic, readonly) BOOL canBeHidden;
@property (nonatomic, readonly) BOOL canBeDisplayed;

@property (nonatomic, readonly, nullable) UIViewController *viewController;

@property (nonatomic, readonly, copy) NSString *cellIdentifier;
@property (nonatomic, readonly) CGFloat cellHeight;

@property (nonatomic, readonly, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END
