//
//  FIDynamicAction.h
//  FIDynamicViewController
//
//  Created by NGUYEN CHI CONG on 8/17/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FIDynamicAction : NSObject

- (instancetype _Nonnull)initWithSelectorName: (NSString *__nullable)selector withObject: (id __nullable)object;

@property (nonatomic, strong) NSString *__nullable selector;
@property (nonatomic, strong) id __nullable object;
@property (nonatomic) BOOL performOnBackground;

@end
