//
//  FIBaseSubViewController.h
//  FIDynamicViewController
//
//  Created by NGUYEN CHI CONG on 8/7/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FISubViewControllerProtocol.h"
#import "FIDynamicViewControllerProtocol.h"

@class FIBaseSubViewController;

@interface FIBaseSubViewController : UIViewController <FISubViewControllerProtocol>

@property (nonatomic, weak) UIView * __nullable fitContentView;
@property (nonatomic, weak) id __nullable dynamicModel;
@property (nonatomic, weak) id<FIDynamicViewControllerProtocol> __nullable containerController;




/**
    Call this method when update presenter model
*/
- (void)updatePresenterWithBlock: (void(^ __nullable)()) block;
- (void)updatePresenterProperty:(SEL __nonnull) selector withBlock:(void(^ __nullable)( id __nullable value)) block;
/**
 Call this method when has update layout at sub view controller
 */
- (void)needUpdateLayout;





#pragma mark - Override
/*------------------------------------------------------*/
/**
  Override this methods to handle when presenter updated
*/
- (void)presenterNeedUpdate;

- (void)presenterDidLoad;

- (void)presenterChangedValue: (id __nullable)value keyPath:(NSString * __nonnull)keyPath;



#pragma mark - deprecated
/*------------------------------------------------------*/
- (void)needUpdateLayoutAnimated:(BOOL)animated __attribute__((deprecated("This method has been deprecated and will be removed in laster version. Please use needUpdateLayout instead.")));

@end
