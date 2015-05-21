//
//  ODAddRelationOperation.h
//  Pods
//
//  Created by Rick Mak on 18/5/15.
//
//

#import "ODOperation.h"

@interface ODAddRelationsOperation : ODOperation


/**
 Instantiates an instance of <ODAddRelationsOperation> with a list of user to be related with current user.
 
 @param records An array of users to be related.
 */
- (instancetype)initWithType:(NSString *)relationType usersToRelated:(NSArray *)users;

/**
 Type of the relation, default provide `follow` and `friend`.
 */
@property (nonatomic, copy) NSString *relationType;

/**
 Sets or returns an array of users to be related.
 */
@property (nonatomic, copy) NSArray *usersToRelate;


/**
 Sets or returns a block to be called when the save operation for individual record is completed.
 If an error occurred during the save, the <NSError> will be specified.
 */
@property (nonatomic, copy) void (^perUserCompletionBlock)(ODUserRecordID *userID, NSError *error);

/**
 Sets or returns a block to be called when the entire operation completes. If the entire operation
 results in an error, the <NSError> will be specified.
 */
@property (nonatomic, copy) void (^addRelationsCompletionBlock)(NSArray *savedUserIDs, NSError *operationError);


@end