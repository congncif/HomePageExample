//
//  UIView+animation.h
//  FIDynamicViewController
//
//  Created by FOLY on 12/26/15.
//  Copyright © 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (animation)

- (void)addSubview:(UIView *)view animated:(BOOL)animated direction: (NSString *)direction;
- (void)addSubview:(UIView *)view transitionType: (NSString *)type animated:(BOOL)animated direction: (NSString *)direction;

- (void)animation:(void(^)())block transitionType: (NSString *)type animated:(BOOL)animated direction: (NSString *)direction;

- (void)animation:(void(^)())block delay:(void(^)())delayBlock transitionType: (NSString *)type animated:(BOOL)animated direction: (NSString *)direction;

- (void)animationFadeOut: (BOOL)fadeOut;
- (void)animationFadeOut: (BOOL)fadeOut completion: (void(^)(BOOL finished))completionBlock;

@end
