//
//  SKYRecord_Private.h
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

#import "SKYRecord.h"

@interface SKYRecord ()

@property (nonatomic, readwrite, copy) SKYRecordID *recordID;
@property (nonatomic, readwrite, copy) SKYUserRecordID *ownerUserRecordID;
@property (nonatomic, readwrite, copy) NSDate *creationDate;
@property (nonatomic, readwrite, copy) SKYUserRecordID *creatorUserRecordID;
@property (nonatomic, readwrite, copy) NSDate *modificationDate;
@property (nonatomic, readwrite, copy) SKYUserRecordID *lastModifiedUserRecordID;
@property (strong, nonatomic, readwrite) SKYAccessControl *accessControl;

@end
