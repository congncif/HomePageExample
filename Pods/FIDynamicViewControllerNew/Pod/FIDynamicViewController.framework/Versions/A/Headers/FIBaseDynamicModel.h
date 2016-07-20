//
//  FIBaseDynamicPreseneter.h
//  StoryboardDemo
//
//  Created by NGUYEN CHI CONG on 8/7/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "FIDynamicPresenterProtocol.h"

@interface FIBaseDynamicModel : NSObject <FIDynamicModelProtocol>

@property (nonatomic, weak) id<FIDynamicObservableDelegate> delegate;

@end
