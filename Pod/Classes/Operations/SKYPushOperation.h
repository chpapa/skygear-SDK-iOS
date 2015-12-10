//
//  SKYPushOperation.h
//  SkyKit
//
//  Copyright 2015 Oursky Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#import "SKYOperation.h"

#import "SKYNotificationInfo.h"
#import "SKYUserRecordID.h"

@interface SKYPushOperation : SKYOperation

- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                            alertBody:(NSString *)alertBody;
- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                            alertBody:(NSString *)alertBody
           alertActionLocalizationKey:(NSString *)alertActionLocalizationKey;
- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                            alertBody:(NSString *)alertBody
           alertActionLocalizationKey:(NSString *)alertActionLocalizationKey
                            soundName:(NSString *)soundName;

- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                 alertLocalizationKey:(NSString *)alertLocalizationKey
                alertLocalizationArgs:(NSArray *)alertLocalizationArgs;
- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                 alertLocalizationKey:(NSString *)alertLocalizationKey
                alertLocalizationArgs:(NSArray *)alertLocalizationArgs
           alertActionLocalizationKey:(NSString *)alertActionLocalizationKey;
- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                 alertLocalizationKey:(NSString *)alertLocalizationKey
                alertLocalizationArgs:(NSArray *)alertLocalizationArgs
           alertActionLocalizationKey:(NSString *)alertActionLocalizationKey
                            soundName:(NSString *)soundName;

- (instancetype)initWithUserRecordID:(SKYUserRecordID *)userRecordID
                    notificationInfo:(SKYNotificationInfo *)notificationInfo;
- (instancetype)initWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                     notificationInfo:(SKYNotificationInfo *)notificationInfo
    NS_DESIGNATED_INITIALIZER;

+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                                 alertBody:(NSString *)alertBody;
+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                                 alertBody:(NSString *)alertBody
                alertActionLocalizationKey:(NSString *)alertActionLocalizationKey;
+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                                 alertBody:(NSString *)alertBody
                alertActionLocalizationKey:(NSString *)alertActionLocalizationKey
                                 soundName:(NSString *)soundName;

+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                      alertLocalizationKey:(NSString *)alertLocalizationKey
                     alertLocalizationArgs:(NSArray *)alertLocalizationArgs;
+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                      alertLocalizationKey:(NSString *)alertLocalizationKey
                     alertLocalizationArgs:(NSArray *)alertLocalizationArgs
                alertActionLocalizationKey:(NSString *)alertActionLocalizationKey;
+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                      alertLocalizationKey:(NSString *)alertLocalizationKey
                     alertLocalizationArgs:(NSArray *)alertLocalizationArgs
                alertActionLocalizationKey:(NSString *)alertActionLocalizationKey
                                 soundName:(NSString *)soundName;

+ (instancetype)operationWithUserRecordID:(SKYUserRecordID *)userRecordID
                         notificationInfo:(SKYNotificationInfo *)notificationInfo;
+ (instancetype)operationWithUserRecordIDs:(NSArray /* SKYUserRecordID */ *)userRecordIDs
                          notificationInfo:(SKYNotificationInfo *)notificationInfo;

@property (nonatomic, copy) NSArray *userRecordIDs;

/**
 The configuration of notifications sent by this operation.

 ## Discussion

 For an opertion object not created by the family of `init` methods that receive a
 `SKYNotificationInfo` object, the notificationInfo object created will have the shouldBadge
 property equalled YES by default.

 If configuration of properties `alertLaunchImage`, `shouldBadge` or `shouldSendContentAvailable` is
 desired, create and set a new `SKYNotificationInfo` object manually or use the `-[SKYPushOperation
 initWithUserRecordIDs:notificationInfo:]` initializer. The value of property `desiredKeys`
 configured on such notificationInfo will be ignored.

 If this property is nil when the operation starts, an NSInternalInconsistencyException will be
 thrown.
 */
@property (nonatomic, copy) SKYNotificationInfo *notificationInfo;

@property (nonatomic, copy) void (^perUserRecordIDCompletionBlock)
    (SKYUserRecordID *userRecordID, NSError *error);
@property (nonatomic, copy) void (^pushCompletionBlock)(NSError *error);

@end
