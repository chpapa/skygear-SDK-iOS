//
//  ODAddRelationsOperationTests.m
//  ODKit
//
//  Created by Rick Mak on 19/5/15.
//  Copyright (c) 2015 Kwok-kuen Cheung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ODKit/ODKit.h>
#import <OHHTTPStubs/OHHTTPStubs.h>

SpecBegin(ODRemoveRelationsOperation)

describe(@"relation add", ^{
    __block ODUser *follower1 = nil;
    __block ODUser *follower2 = nil;
    __block ODContainer *container = nil;
    
    beforeEach(^{
        container = [[ODContainer alloc] init];
        [container updateWithUserRecordID:[[ODUserRecordID alloc] initWithRecordType:@"user" name:@"USER_ID"]
                              accessToken:[[ODAccessToken alloc] initWithTokenString:@"ACCESS_TOKEN"]];
        ODUserRecordID *userRecordID = [[ODUserRecordID alloc] initWithRecordType:@"user" name:@"user1001"];
        follower1 = [[ODUser alloc] initWithUserRecordID:userRecordID];
        userRecordID = [[ODUserRecordID alloc] initWithRecordType:@"user" name:@"user1002"];
        follower2 = [[ODUser alloc] initWithUserRecordID:userRecordID];
    });
    
    it(@"multiple relations", ^{
        ODRemoveRelationsOperation *operation = [[ODRemoveRelationsOperation alloc] initWithType:@"follow" usersToRemove:@[follower1, follower2]];
        operation.container = container;
        [operation prepareForRequest];
        ODRequest *request = operation.request;
        expect([request class]).to.beSubclassOf([ODRequest class]);
        expect(request.action).to.equal(@"relation:delete");
        expect(request.payload[@"name"]).to.equal(@"follow");
        expect(request.payload[@"targets"]).to.haveCountOf(2);
        expect(request.accessToken).to.equal(container.currentAccessToken);
        
        expect(request.payload[@"targets"][0]).to.equal(@"user/user1001");
        expect(request.payload[@"targets"][1]).to.equal(@"user/user1002");
    });
    
    it(@"make request", ^{
        ODRemoveRelationsOperation *operation = [[ODRemoveRelationsOperation alloc] initWithType:@"follow" usersToRemove:@[follower1, follower2]];
        
        [OHHTTPStubs stubRequestsPassingTest:^BOOL(NSURLRequest *request) {
            return YES;
        } withStubResponse:^OHHTTPStubsResponse *(NSURLRequest *request) {
            NSDictionary *parameters = @{
                                         @"request_id": @"REQUEST_ID",
                                         @"result": @[
                                                 @{
                                                     @"_id": @"user/user1001",
                                                     },
                                                 @{
                                                     @"_id": @"user/user1002",
                                                     @"_type": @"error",
                                                     @"message": @"cannot find user",
                                                     @"code": @"ResourceNotFound",
                                                     }
                                                 ]
                                         };
            NSData *payload = [NSJSONSerialization dataWithJSONObject:parameters
                                                              options:0
                                                                error:nil];
            
            return [OHHTTPStubsResponse responseWithData:payload
                                              statusCode:200
                                                 headers:@{}];
        }];
        
        waitUntil(^(DoneCallback done) {
            operation.removeRelationsCompletionBlock = ^(NSArray *deletedUserIDs, NSError *operationError) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    expect([deletedUserIDs class]).to.beSubclassOf([NSArray class]);
                    expect(deletedUserIDs).to.haveCountOf(1);
                    expect(deletedUserIDs[0]).to.equal(follower1.recordID);
                    expect(operationError).toNot.beNil();
                    done();
                });
            };
            
            [container addOperation:operation];
        });
    });
    
    afterEach(^{
        [OHHTTPStubs removeAllStubs];
    });
});

SpecEnd