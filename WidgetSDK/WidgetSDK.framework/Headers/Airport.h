//
//  Airport.h
//  App in the Air
//
//  Created by Sergey Pronin on 05.08.11.
//  Copyright 2011 App in the Air. All rights reserved.
//

@import Foundation;
@import CoreLocation;

#import "AitaStoredObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface Airport : AitaStoredObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *country;
@property (nonatomic, strong) NSString *countryFullName;
@property (nonatomic) double_t offset;
@property (nonatomic) double_t latitude;
@property (nonatomic) double_t longitude;
@property (nonatomic, strong, nullable) NSString *venueID;
@property (nonatomic, strong, nullable) NSString *phone;
@property (nonatomic, strong, nullable) NSString *url;
@property (nonatomic, strong, nullable) NSString *continent;
@property (nonatomic) double_t taxiPrice;

@property (nonatomic, readonly) NSString *localizedName;
@property (nonatomic, readonly) NSString *localizedCity;
@property (nonatomic, readonly) NSString *localizedCountry;

@property (nonatomic, readonly) CLLocationCoordinate2D location;

///once in 12 hours
@property (nonatomic, readonly) BOOL canLeaveCrowdsource;

@property (nonatomic) BOOL canBeLocalized;

@property (nonatomic, readonly) NSDate *currentDatetime;

@end

NS_ASSUME_NONNULL_END