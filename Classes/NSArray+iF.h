//
//  NSArray+iF.h
//  JMHomeScreen2
//
//  Created by FOLY on 1/22/16.
//  Copyright © 2016 FOLY. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (iF)

long reduceCount(long count, long numberInLine);

- (NSArray *)subArrayWithLineSize: (NSInteger)numberItemInLine;

@end
