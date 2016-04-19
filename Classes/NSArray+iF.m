//
//  NSArray+iF.m
//  JMHomeScreen2
//
//  Created by FOLY on 1/22/16.
//  Copyright © 2016 FOLY. All rights reserved.
//

#import "NSArray+iF.h"

@implementation NSArray (iF)

long reduceCount(long count, long numberInLine) {
    if (numberInLine <= 0 || numberInLine >= count) {
        return count;
    }
    
    long reduce = count % numberInLine;
    reduce = count - reduce;
    return reduce;
}

- (NSArray *)subArrayWithLineSize: (NSInteger)numberItemInLine{
    
    NSInteger count = (NSInteger) reduceCount((long)self.count, (long)numberItemInLine);
    return [self subarrayWithRange:NSMakeRange(0, count)];
    
}

@end
