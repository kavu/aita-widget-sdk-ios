//
//  Flight.h
//  App in the Air
//
//  Created by Sergey Pronin on 05.08.11.
//  Copyright 2011 App in the Air. All rights reserved.
//

#import "AitaStoredObject.h"
#import "Airport.h"
#import "Aircraft.h"
#import "Airline.h"

NS_ASSUME_NONNULL_BEGIN

@import Foundation;

@class Todo;
@class Trip;

typedef NS_ENUM(NSInteger, TimelineFlightEvent) {
    TimelineFlightEventCheckin,
    TimelineFlightEventBoarding,
    TimelineFlightEventTakeoff,
    TimelineFlightEventLanding,
    TimelineFlightEventFinished,
    TimelineFlightEventCheckinOpened
};

@interface FlightInfo : AitaStoredObject

@property (nonatomic, strong) NSString *airlineCode;
@property (nonatomic, strong) NSDate *departureDatetime;

@property (nonatomic, strong) NSString * __null_unspecified historyID DEPRECATED_MSG_ATTRIBUTE("Use flightID");

@property (nonatomic, strong) NSString * __null_unspecified flightID;

@property (nonatomic, strong, nullable) NSString *status;
@property (nonatomic, strong) NSString *number;
@property (nonatomic) BOOL smsEnabled;
@property (nonatomic) BOOL purchased;
@property (nonatomic) BOOL finished;
@property (nonatomic) BOOL pushEnabled;
@property (nonatomic, strong) NSNumber *departureOffset;
@property (nonatomic, strong) NSNumber *arrivalOffset;
@property (nonatomic) BOOL checkedIn;
@property (nonatomic, strong, nullable) NSDate *departureDatetimeRunwayEstimate;
@property (nonatomic, strong, nullable) NSDate *arrivalDatetimeRunwayEstimate;
@property (nonatomic, strong, nullable) NSDate *arrivalDatetimeActual;
@property (nonatomic, strong, nullable) NSDate *departureDatetimeRunwaySchedule;
@property (nonatomic, strong, nullable) NSDate *arrivalDatetimeRunwaySchedule;
@property (nonatomic, strong, nullable) NSString *arrivalTerminal;
@property (nonatomic, strong, nullable) NSString *arrivalGate;
@property (nonatomic, strong, nullable) NSString * aircraft;
@property (nonatomic, strong) NSDate *arrivalDatetime;
@property (nonatomic) int32_t arrivalDelayActual;
@property (nonatomic, strong, nullable) NSDate *arrivalDatetimeEstimate;
@property (nonatomic) int32_t departureDelayActual;
@property (nonatomic, strong, nullable) NSDate *departureDatetimeEstimate;
@property (nonatomic, strong, nullable) NSString *departureTerminal;
@property (nonatomic, strong, nullable) NSString *departureGate;
@property (nonatomic, strong) NSDate *lastUpdated;
@property (nonatomic, strong) NSDate *createdAt;
///distance in km
@property (nonatomic) int32_t distance;
@property (nonatomic, strong, nullable) NSDate *departureDatetimeDelayed;
@property (nonatomic, strong, nullable) NSString *customNote;
@property (nonatomic, strong) NSDate *departureDatetimeUTC;
@property (nonatomic, strong) NSDate *arrivalDatetimeUTC;
///flight duration in minutes
@property (nonatomic) int32_t duration;
@property (nonatomic, strong) NSString *airlineName;
@property (nonatomic, strong, nullable) NSString *baggageBelt;
@property (nonatomic, strong) NSString * __null_unspecified source;

@property (nonatomic, strong, nullable) NSString *seatNumber;
@property (nonatomic, strong, nullable) NSString *seatClass;
@property (nonatomic, strong, nullable) NSString *bookingReference;

@property (nonatomic) BOOL doneCheckin;
@property (nonatomic) BOOL doneBoarding;
@property (nonatomic) BOOL doneTakeoff;

@property (nonatomic) BOOL canceledManually;

@property (nonatomic, readonly) BOOL isCanceled;

@property (nonatomic) int16_t departureHour;
@property (nonatomic) int16_t arrivalHour;

@property (nonatomic, strong) Airport *airportOrigin;
@property (nonatomic, strong) Airport *airportDestination;
@property (nonatomic, strong) Airline *airline;

@property (nonatomic, strong) Trip * __null_unspecified trip;

@property (nonatomic, strong, nullable) Aircraft *aircraftObject;

@property (nonatomic) BOOL isSample;

@property (nonatomic, readonly) BOOL isInFuture;
@property (nonatomic, readonly) BOOL isEnded;

@property (readonly) NSDate *dateBoardingEnd;
@property (readonly) NSDate *dateCheckinEnd;
@property (readonly) NSDate *dateLanding;
@property (readonly) NSDate *dateTakeoff;

@property (readonly) NSDate *dateBoardingEndUTC;
@property (readonly) NSDate *dateCheckinEndUTC;
@property (readonly) NSDate *dateLandingUTC;
@property (readonly) NSDate *dateTakeoffUTC;

@property (readonly) NSDate *dateBoardingStart;
@property (readonly) NSDate *dateCheckinStart;

@property (readonly) NSDate *dateBoardingStartUTC;
@property (readonly) NSDate *dateCheckinStartUTC;

@property (readonly) TimelineFlightEvent relevantEvent;

@property (readonly) NSString *name;

@property (nonatomic) int16_t gateWalkTime;

@property (readonly, nullable) NSDate *arrivalDatetimeDelayed;

- (BOOL)isEventRelevant:(TimelineFlightEvent)event;

@end

NS_ASSUME_NONNULL_END
