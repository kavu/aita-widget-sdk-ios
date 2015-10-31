//
//  Trip.h
//  App in the Air
//
//  Created by Sergey Pronin on 2/13/15.
//  Copyright (c) 2015 App in the Air. All rights reserved.
//

@import Foundation;
@import CoreData;

#import "AitaStoredObject.h"

@class FlightInfo;
@class Note;
@class Todo;

NS_ASSUME_NONNULL_BEGIN

@interface Trip : AitaStoredObject

@property (nonatomic, strong) NSString *tripID;

@property (nonatomic, strong) NSDate *departureDatetime;
@property (nonatomic, strong) NSDate *departureDatetimeUTC;

@property (nonatomic, strong) NSDate *arrivalDatetime;
@property (nonatomic, strong) NSDate *arrivalDatetimeUTC;

@property (nonatomic, strong) NSOrderedSet<FlightInfo *> *flights;
@property (nonatomic, strong) NSOrderedSet<Note *> *notes;
@property (nonatomic, strong) NSOrderedSet<Todo *> *todos;

@property (nonatomic, strong) NSDate *updatedAt;
@property (nonatomic, strong) NSDate *createdAt;

@property (nonatomic) BOOL alertsPurchased;
@property (nonatomic) BOOL smsPurchased;

@property (nonatomic) BOOL pushEnabled;

@property (nonatomic, readonly) BOOL isSample;

@property (nonatomic, strong) NSString *departureAirportCode;
@property (nonatomic, strong) NSString *arrivalAirportCode;

#pragma mark - Helper properties

@property (nonatomic, readonly) FlightInfo *firstFlight;
@property (nonatomic, readonly) FlightInfo *lastFlight;

///returns active flights (not-landed) or the last one if all flights are past ones
@property (nonatomic, readonly) FlightInfo *activeFlight;

///index in `flights` ordered set or -1 if all flights are past ones
@property (nonatomic, readonly) NSInteger activeFlightIndex;

///channel name for Parse Push notifications
@property (nonatomic, readonly) NSString *pushChannelName;

///duration from the first take-off to the last landing (including layovers)
@property (nonatomic, readonly) NSTimeInterval duration;

///sum of duration for each individual flight (excluding layovers)
@property (nonatomic, readonly) NSTimeInterval flyingDuration;

///name of the trip, e.g. "Moscow — San Francisco"
@property (nonatomic, readonly) NSString *name;

@property (nonatomic, readonly) BOOL isInFuture;
@property (nonatomic, readonly) BOOL isEnded;

@property (nonatomic, readonly) NSInteger doneTodos;

- (nullable FlightInfo *)flightBeforeFlight:(FlightInfo *)flight;
- (NSTimeInterval)layoverBeforeFlight:(FlightInfo *)flight;

- (nullable FlightInfo *)flightAfterFlight:(FlightInfo *)flight;
- (NSTimeInterval)layoverAfterFlight:(FlightInfo *)flight;

- (void)reorderFlights;

@end

NS_ASSUME_NONNULL_END