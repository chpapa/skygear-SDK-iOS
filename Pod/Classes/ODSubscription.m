//
//  ODSubscription.m
//  askq
//
//  Created by Kenji Pa on 29/1/15.
//  Copyright (c) 2015 Rocky Chan. All rights reserved.
//

#import "ODSubscription.h"

@interface ODSubscription()

@property (nonatomic, copy) NSString *subscriptionID;
@property (nonatomic, readwrite, assign) ODSubscriptionType subscriptionType;

@end

@implementation ODSubscription

- (instancetype)initWithQuery:(ODQuery *)query {
    return [self initWithQuery:query subscriptionID:nil];
}

- (instancetype)initWithQuery:(ODQuery *)query
                 subscriptionID:(NSString *)subscriptionID {
    self = [super init];
    if (self) {
        _subscriptionType = ODSubscriptionTypeQuery;
        _query = query;
        _subscriptionID = subscriptionID;
    }
    return self;
}

+ (instancetype)subscriptionWithQuery:(ODQuery *)query
{
    return [[self alloc] initWithQuery:query];
}

+ (instancetype)subscriptionWithQuery:(ODQuery *)query
                       subscriptionID:(NSString *)subscriptionID
{
    return [[self alloc] initWithQuery:query subscriptionID:subscriptionID];
}

@end
