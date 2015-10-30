//
//  Aircraft.h
//  App in the Air
//
//  Created by Sergey Pronin on 03/09/2011.
//  Copyright 2011 App in the Air. All rights reserved.
//

@import Foundation;
#import "AitaStoredObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface Aircraft : AitaStoredObject

@property (nonatomic, strong) NSString *model;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *code;
@property (nonatomic, strong, nullable) NSString *infoUrl;

@end

NS_ASSUME_NONNULL_END