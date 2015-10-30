//
//  FlightInfo+Sample.swift
//  AppInTheAirWidgetSDK
//
//  Created by Sergey Pronin on 10/23/15.
//  Copyright © 2015 App in the Air. All rights reserved.
//

import UIKit
import WidgetSDK

extension Airport {
    class var sampleAirport_SVO: Airport {
        let airport = Airport()
        airport.city = "Moscow"
        airport.code = "SVO"
        airport.name = "Sheremetyevo Airport"
        airport.offset = 3
        airport.latitude = 55.966324
        airport.longitude = 37.416573
        airport.country = "RU"
        airport.countryFullName = "Russian Federation"
        return airport
    }

    
    class var sampleAirport_JFK: Airport {
        let airport = Airport()
        airport.city = "New York"
        airport.code = "JFK"
        airport.name = "John F. Kennedy International Airport"
        airport.offset = -4
        airport.latitude = 40.642334
        airport.longitude = -73.78817
        airport.country = "US"
        airport.countryFullName = "United States"
        return airport
    }
}

extension FlightInfo {
    class var sampleFlight: FlightInfo {
        let flight = FlightInfo()
        flight.airportOrigin = Airport.sampleAirport_SVO
        flight.airportDestination = Airport.sampleAirport_JFK
        flight.airlineCode = "AA"
        flight.number = "100"
        flight.departureDatetime = NSDate(timeIntervalSinceNow: 3600)
        flight.arrivalDatetime = NSDate(timeIntervalSinceNow: 12*3600)
        flight.flightID = "sample"
        flight.departureGate = "40"
        flight.departureTerminal = "F"
        flight.arrivalGate = "88"
        flight.arrivalTerminal = "A"
        return flight
    }
}


extension Trip {
    class var sampleTrip: Trip {
        let trip = Trip()
        let flight = FlightInfo.sampleFlight
        flight.trip = trip
        trip.departureDatetime = flight.departureDatetime
        trip.departureDatetimeUTC = flight.departureDatetimeUTC
        trip.arrivalDatetime = flight.arrivalDatetime
        trip.arrivalDatetimeUTC = flight.arrivalDatetimeUTC
        trip.tripID = "sample"
        trip.flights = NSOrderedSet(object: flight)
        trip.arrivalAirportCode = "LED"
        return trip
    }
}
