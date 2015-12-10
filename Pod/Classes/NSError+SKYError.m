//
//  NSError+SKYError.m
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

#import "NSError+SKYError.h"
#import "SKYError.h"

@implementation NSError (SKYError)

- (NSInteger)SKYErrorCode
{
    NSNumber *code = [self userInfo][SKYErrorCodeKey];
    return [code isKindOfClass:[NSNumber class]] ? [code integerValue] : 0;
}

- (NSString *)SKYErrorMessage
{
    NSString *message = [self userInfo][SKYErrorMessageKey];
    return [message isKindOfClass:[NSString class]] ? message : nil;
}

- (NSString *)SKYErrorType
{
    NSString *type = [self userInfo][SKYErrorTypeKey];
    return [type isKindOfClass:[NSString class]] ? type : nil;
}

- (NSDictionary *)SKYErrorInfo
{
    NSDictionary *info = [self userInfo][SKYErrorInfoKey];
    return [info isKindOfClass:[NSDictionary class]] ? info : nil;
}

@end
