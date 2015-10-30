//
//  Airline.h
//  App in the Air
//
//  Created by Sergey Pronin on 04/09/2011.
//  Copyright 2011 App in the Air. All rights reserved.
//

@import Foundation;
#import "AitaStoredObject.h"

NS_ASSUME_NONNULL_BEGIN
@interface Airline : AitaStoredObject

@property (nonatomic, strong, nullable) NSString *email;
@property (nonatomic, strong, nullable) NSString *phone;
@property (nonatomic, strong, nullable) NSNumber *checkinAvailable;
@property (nonatomic, strong) NSString *iataCode;
@property (nonatomic, strong) NSString *icaoCode;
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong, nullable) NSString *twitter;
@property (nonatomic, strong, nullable) NSString *websiteUrl;

@property (nonatomic, strong, nullable) NSNumber *checkinCloseDomestic;        //minutes
@property (nonatomic, strong, nullable) NSNumber *checkinCloseInternational;   //minutes
@property (nonatomic, strong, nullable) NSNumber *checkinOpenHrs;

@end

NS_ASSUME_NONNULL_END
