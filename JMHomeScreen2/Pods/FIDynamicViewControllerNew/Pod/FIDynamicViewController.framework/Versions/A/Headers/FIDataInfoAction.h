//
//  FIDataInfoAction.h
//  FIDynamicViewController
//
//  Created by FOLY on 12/26/15.
//  Copyright © 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FIDataInfoAction : NSObject

- (instancetype _Nonnull)initWithCommand: (NSString * __nullable)command withObject: (id __nullable)object;

@property (nonatomic, strong) NSString * __nullable command;
@property (nonatomic, strong) id __nullable object;

@end
